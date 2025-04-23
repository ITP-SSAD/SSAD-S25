#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// TODO: Create a Command interface with execute() and undo() methods
class Command {
public:
    virtual ~Command() {}
    // TODO: Add pure virtual methods for execute() and undo()
};

class TextEditor {
private:
    string text;
    string clipboard;

public:
    void addText(const string& newText) {
        text += newText;
    }

    void replaceText(const string& newText) {
        text = newText;
    }

    string getText() const {
        return text;
    }

    void setClipboard(const string& text) {
        clipboard = text;
    }

    string getClipboard() const {
        return clipboard;
    }
};

// TODO: Implement CopyCommand that inherits from Command
class CopyCommand : public Command {
private:
    TextEditor* editor;
    string backup;

public:
    CopyCommand(TextEditor* editor) : editor(editor) {}

    // TODO: Implement execute() method that:
    // 1. Saves backup of current text
    // 2. Copies text to clipboard
    // 3. Returns true

    // TODO: Implement undo() method that restores text from backup
};

// TODO: Implement PasteCommand that inherits from Command
class PasteCommand : public Command {
private:
    TextEditor* editor;
    string backup;

public:
    PasteCommand(TextEditor* editor) : editor(editor) {}

    // TODO: Implement execute() method that:
    // 1. Saves backup of current text
    // 2. Pastes text from clipboard to editor
    // 3. Returns true

    // TODO: Implement undo() method that restores text from backup
};

class CommandHistory {
private:
    vector<unique_ptr<Command>> history;

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

    cout << "Enter text: ";
    string input;
    getline(cin, input);
    editor.addText(input);

    // Assume user wants to copy and then paste
    Command* copy = new CopyCommand(&editor);
    Command* paste = new PasteCommand(&editor);

    copy->execute(); // Copy current text
    paste->execute(); // Paste text
    history.push(copy);
    history.push(paste);

    cout << "Current text: " << editor.getText() << endl;

    // Undo last command
    if (!history.isEmpty()) {
        Command* cmd = history.pop();
        cmd->undo();
        delete cmd;
        cout << "Text after undo: " << editor.getText() << endl;
    }

    // Cleanup remaining commands
    while (!history.isEmpty()) {
        delete history.pop();
    }

    return 0;
}