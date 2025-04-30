#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Command {
public:
    virtual ~Command() {}
    virtual bool execute() = 0;
    virtual void undo() = 0;
};

class TextEditor {
private:
    std::string text;
    std::string clipboard;

public:
    void addText(const std::string& newText) {
        text += newText;
    }

    void replaceText(const std::string& newText) {
        text = newText;
    }

    std::string getText() const {
        return text;
    }

    void setClipboard(const std::string& text) {
        clipboard = text;
    }

    std::string getClipboard() const {
        return clipboard;
    }
};

class CopyCommand : public Command {
private:
    TextEditor* editor;
    std::string backup;

public:
    CopyCommand(TextEditor* editor) : editor(editor) {}

    bool execute() override {
        backup = editor->getText();
        editor->setClipboard(backup);
        return true;
    }

    void undo() override {
        editor->replaceText(backup);
    }
};

class PasteCommand : public Command {
private:
    TextEditor* editor;
    std::string backup;

public:
    PasteCommand(TextEditor* editor) : editor(editor) {}

    bool execute() override {
        backup = editor->getText();
        editor->addText(editor->getClipboard());
        return true;
    }

    void undo() override {
        editor->replaceText(backup);
    }
};

class CommandHistory {
private:
    std::vector<std::unique_ptr<Command>> history;

public:
    void push(Command* cmd) {
        history.emplace_back(cmd);
    }

    Command* pop() {
        if (history.empty()) return nullptr;
        auto cmd = history.back().release();
        history.pop_back();
        return cmd;
    }

    bool isEmpty() const {
        return history.empty();
    }
};

int main() {
    TextEditor editor;
    CommandHistory history;

    std::cout << "Enter text: ";
    std::string input;
    std::getline(std::cin, input);
    editor.addText(input);

    // Assume user wants to copy and then paste
    Command* copy = new CopyCommand(&editor);
    Command* paste = new PasteCommand(&editor);

    copy->execute(); // Copy current text
    paste->execute(); // Paste text
    history.push(copy);
    history.push(paste);

    std::cout << "Duplicated text: " << editor.getText() << std::endl;

    // Undo last command
    if (!history.isEmpty()) {
        Command* cmd = history.pop();
        cmd->undo();
        delete cmd;
        std::cout << "Text after undo: " << editor.getText() << std::endl;
    }

    // Cleanup remaining commands
    while (!history.isEmpty()) {
        delete history.pop();
    }

    return 0;
}