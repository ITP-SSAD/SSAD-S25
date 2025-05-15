#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Memento: stores a snapshot of TextEditor’s text
class Memento {
public:
    Memento(const string& state) : state(state) {}
    string getState() const { return state; }
private:
    string state;
};

// Originator: allows text modification and state save/restore
class TextEditor {
public:
    TextEditor() : text("") {}

    void appendText(const string& newText) {
        text += newText;
    }

    string getText() const {
        return text;
    }

    Memento save() const {
        return Memento(text);
    }

    void restore(const Memento& memento) {
        text = memento.getState();
    }

private:
    string text;
};

// Caretaker: handles undo/redo via two stacks of Mementos
class UndoRedoManager {
public:
    UndoRedoManager() = default;

    void saveState(TextEditor& editor) {
        // save current state, clear redo history
        undoStack.push(editor.save());
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo(TextEditor& editor) {
        if (undoStack.size() > 1) {
            // move latest into redo, restore previous
            Memento top = undoStack.top();
            undoStack.pop();
            redoStack.push(top);

            Memento prev = undoStack.top();
            editor.restore(prev);
        }
        else if (undoStack.size() == 1) {
            // only one state saved: undo back to empty
            Memento top = undoStack.top();
            undoStack.pop();
            redoStack.push(top);

            editor.restore(Memento("")); 
        }
    }

    void redo(TextEditor& editor) {
        if (!redoStack.empty()) {
            Memento m = redoStack.top();
            redoStack.pop();
            editor.restore(m);
            undoStack.push(m);
        }
    }

private:
    stack<Memento> undoStack;
    stack<Memento> redoStack;
};

int main() {
    TextEditor editor;
    UndoRedoManager undoRedoManager;

    cout << "Initial text: " << editor.getText() << endl;

    editor.appendText("Hello");
    undoRedoManager.saveState(editor);
    cout << "After appending 'Hello': " << editor.getText() << endl;

    editor.appendText(" World");
    undoRedoManager.saveState(editor);
    cout << "After appending ' World': " << editor.getText() << endl;

    undoRedoManager.undo(editor);
    cout << "After undoing: " << editor.getText() << endl;

    undoRedoManager.redo(editor);
    cout << "After redoing: " << editor.getText() << endl;

    return 0;
}
