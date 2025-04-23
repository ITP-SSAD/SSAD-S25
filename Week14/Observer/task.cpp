#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class File {
public:
    string path;
    File(const string& path) : path(path) {}
};

class EventListener {
public:
    virtual ~EventListener() = default;
    virtual void update(const string& eventType, const File& file) = 0;
};

class EventManager {
private:
    map<string, vector<shared_ptr<EventListener>>> listeners;

public:
    EventManager(const vector<string>& operations) {
        // TODO: Initialize listeners map with empty vectors for each operation
    }

    void subscribe(const string& eventType, shared_ptr<EventListener> listener) {
        // TODO: Add listener to the eventType's list
    }

    void unsubscribe(const string& eventType, shared_ptr<EventListener> listener) {
        // TODO: Remove listener from the eventType's list
    }

    void notify(const string& eventType, const File& file) {
        // TODO: Notify all listeners subscribed to this eventType
    }
};

class Editor {
public:
    unique_ptr<EventManager> events;
    unique_ptr<File> file;

    Editor() {
        // TODO: Initialize EventManager with "open" and "save" operations
    }

    void openFile(const string& filePath) {
        file = make_unique<File>(filePath);
        // TODO: Notify listeners about file opening
    }

    void saveFile() {
        if (!file) {
            cerr << "No file is open!" << endl;
            return;
        }
        // TODO: Implement file saving logic
        // TODO: Notify listeners about file saving
    }
};

// TODO: Implement concrete listeners:
// 1. LoggingListener - logs all file operations
// 2. EmailNotificationListener - sends emails on specific events

int main() {
    // TODO: Create editor
    // TODO: Create and subscribe listeners
    // TODO: Test file operations and notifications
    return 0;
}