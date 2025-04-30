#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Memento: holds editor state
class Memento {
public:
    Memento(const string& state);
    string getState() const;
private:
    string state;
};

// Originator: the text editor
class TextEditor {
public:
    TextEditor();
    void appendText(const string& newText);
    string getText() const;

    // TODO: capture current state
    Memento save() const;

    // TODO: restore to a previous state
    void restore(const Memento& memento);
private:
    string text;
};

// Caretaker: manages undo/redo stacks
class UndoRedoManager {
public:
    UndoRedoManager();

    // TODO: push current editor state onto undo stack and clear redo
    void saveState(TextEditor& editor);

    // TODO: pop from undo, push to redo, restore previous
    void undo(TextEditor& editor);

    // TODO: pop from redo, push to undo, restore
    void redo(TextEditor& editor);
private:
    stack<Memento> undoStack;
    stack<Memento> redoStack;
};

int main() {
    TextEditor editor;
    UndoRedoManager undoRedoManager;

    // Initial text
    cout << "Initial text: " << editor.getText() << endl;

    // Append some text and save state
    editor.appendText("Hello");
    undoRedoManager.saveState(editor);
    cout << "After appending 'Hello': " << editor.getText() << endl;

    // Append more text and save state
    editor.appendText(" World");
    undoRedoManager.saveState(editor);
    cout << "After appending ' World': " << editor.getText() << endl;

    // Undo and show state
    undoRedoManager.undo(editor);
    cout << "After undoing: " << editor.getText() << endl;

    // Redo and show state
    undoRedoManager.redo(editor);
    cout << "After redoing: " << editor.getText() << endl;

    return 0;
}
