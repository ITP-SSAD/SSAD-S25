#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

// Forward declarations
class Application;

// 1. Complete the Editor class (Receiver)
class Editor {
private:
    string text;
    string selectedText;

public:
    // TODO: Implement these methods
    void setText(const string& newText) {
        // Set the editor's text content
    }

    string getText() const {
        // Return the full text content
        return "";
    }

    void selectText(size_t start, size_t length) {
        // Select a portion of text (store in selectedText)
    }

    string getSelection() const {
        // Return the currently selected text
        return "";
    }

    void deleteSelection() {
        // Delete the selected text from the main text
    }

    void replaceSelection(const string& replacement) {
        // Replace selected text with new content
    }
};

// 2. Base Command class (already implemented)
class Command {
protected:
    Application* app;
    Editor* editor;
    string backup;

public:
    Command(Application* app, Editor* editor) : app(app), editor(editor) {}
    virtual ~Command() = default;
    
    void saveBackup() {
        backup = editor->getSelection();
    }
    
    void undo() {
        editor->replaceSelection(backup);
    }
    
    virtual bool execute() = 0;
};

// 3. TODO: Implement these concrete commands and add CutCommand, PasteCommand classes
class CopyCommand : public Command {
public:
    using Command::Command;
    
    bool execute() override {
        // Should copy selected text to clipboard
        // Return false because it doesn't modify editor state
        return false;
    }
};


// 4. Command History (TODO: Implement using stack)
class CommandHistory {

};

// 5. Application class (Invoker) - TODO: Complete implementation
class Application {
private:
    string clipboard;
    vector<Editor> editors;
    Editor* activeEditor;
    CommandHistory history;

public:
    Application() {
        // Initialize with one editor and some sample text
        editors.emplace_back();
        activeEditor = &editors.back();
        activeEditor->setText("Sample text for testing commands");
        activeEditor->selectText(0, 6); // Select "Sample"
    }

    void executeCommand(unique_ptr<Command> command) {
        // Execute command and add to history if it modifies state
    }


    void undo() {
        // Undo the most recent command
    }

    // TODO: Implement command triggers: copy(), cut(), paste(), performUndo()

};


int main() {
    Application app;
    
    // TODO: Add test code here to demonstrate the commands
    cout << "Initial text: " << app.getActiveEditor()->getText() << "\n";
    
    return 0;
}
