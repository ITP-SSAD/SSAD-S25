#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

// Handler interface
class Handler {
public:
    virtual ~Handler() = default;
    virtual void setNext(shared_ptr<Handler> next) = 0;
    virtual bool handle(const string& request) = 0;
};

// create abstract base handler

// create concrete handlers: 
// AuthenticationHandler, RoleCheckHandler, ThrottlingHandler (optional)
// handle(request: string) – request contains one of the following:
// valid/invalid/admin


// Client code
void processRequest(const string& request, shared_ptr<Handler> handler) {
    cout << "\nProcessing: " << request << endl;
    if (!handler->handle(request)) {
        cout << "Request denied.\n";
    } else {
        cout << "Request approved.\n";
    }
}

int main() {
    // Build the chain
    auto auth = make_shared<AuthenticationHandler>();
    auto roleCheck = make_shared<RoleCheckHandler>();

    // Test with static requests
    // processRequest("valid", <handler object>);
    // processRequest("admin", <handler object>);
    // processRequest("invalid", <handler object>);

    // Interactive testing
    string input;
    while (true) {
        cout << "\nEnter request type (valid/invalid/admin/quit): ";
        getline(cin, input);

        if (input == "quit") break;

        processRequest(input, <handler object>);
        
        // Small delay to demonstrate throttling window
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}