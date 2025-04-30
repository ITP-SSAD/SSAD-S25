#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using namespace std;

// Represents a file in the editor
class File {
public:
    string path;
    File(const string& path) : path(path) {}
};

// Observer interface
class EventListener {
public:
    virtual ~EventListener() = default;
    virtual void update(const string& eventType, const File& file) = 0;
};

// Manages subscriptions and notifications
class EventManager {
private:
    map<string, vector<shared_ptr<EventListener>>> listeners;

public:
    EventManager(const vector<string>& operations) {
        for (const auto& op : operations) {
            listeners[op] = {};
        }
    }

    void subscribe(const string& eventType, shared_ptr<EventListener> listener) {
        listeners[eventType].push_back(listener);
    }

    void unsubscribe(const string& eventType, shared_ptr<EventListener> listener) {
        auto& vec = listeners[eventType];
        vec.erase(
            remove_if(vec.begin(), vec.end(), [&](const shared_ptr<EventListener>& ptr) {
                return ptr == listener;
            }),
            vec.end()
        );
    }

    void notify(const string& eventType, const File& file) {
        for (auto& listener : listeners[eventType]) {
            listener->update(eventType, file);
        }
    }
};

// Editor that triggers events
class Editor {
public:
    unique_ptr<EventManager> events;
    unique_ptr<File> file;

    Editor() {
        events = make_unique<EventManager>(vector<string>{"open", "save"});
    }

    void openFile(const string& filePath) {
        file = make_unique<File>(filePath);
        cout << "Editor: Opening file '" << filePath << "'..." << endl;
        events->notify("open", *file);
    }

    void saveFile() {
        if (!file) {
            cerr << "Editor Error: No file is open!" << endl;
            return;
        }
        // Simulate file saving
        cout << "Editor: Saving file '" << file->path << "'..." << endl;
        events->notify("save", *file);
    }
};

// Concrete listener that logs events to console
class LoggingListener : public EventListener {
public:
    void update(const string& eventType, const File& file) override {
        cout << "LoggingListener: Detected '" << eventType << "' event for file '" << file.path << "'." << endl;
    }
};

// Concrete listener that sends email notifications (simulated)
class EmailNotificationListener : public EventListener {
private:
    string emailAddress;
public:
    EmailNotificationListener(const string& email) : emailAddress(email) {}

    void update(const string& eventType, const File& file) override {
        cout << "EmailNotificationListener: Sending email to " << emailAddress
             << ": File '" << file.path << "' has been " << eventType << "d." << endl;
    }
};

int main() {
    // Create the editor
    Editor editor;

    // Create listeners
    auto logger = make_shared<LoggingListener>();
    auto emailNotifier = make_shared<EmailNotificationListener>("admin@example.com");

    // Subscribe listeners to events
    editor.events->subscribe("open", logger);
    editor.events->subscribe("save", logger);
    editor.events->subscribe("save", emailNotifier);

    // Test file operations
    editor.openFile("test_document.txt");
    editor.saveFile();

    // Optionally unsubscribe
    // editor.events->unsubscribe("save", emailNotifier);
    // editor.saveFile();

    return 0;
}