#include <iostream>
#include <string>

using namespace std;

// TODO: Create Handler interface with setNext() and handle() methods
class Handler {
public:
    virtual ~Handler() {}
    // TODO: Add pure virtual methods for setNext() and handle()
};

// TODO: Implement AbstractHandler base class that implements Handler
class AbstractHandler : public Handler {
private:
    // TODO: Add next handler pointer
public:
    // TODO: Implement setNext() method
    // TODO: Implement handle() method (base implementation that passes to next)
};

// TODO: Implement AuthenticationHandler that inherits from AbstractHandler
class AuthenticationHandler : public AbstractHandler {
public:
    // TODO: Implement handle() method that:
    // - Returns false if request is not "valid"
    // - Calls handleNext() if request is "valid"
    // - Prints appropriate messages
};

// TODO: Implement RoleCheckHandler that inherits from AbstractHandler
class RoleCheckHandler : public AbstractHandler {
public:
    // TODO: Implement handle() method that:
    // - Returns true if request is "admin"
    // - Calls handleNext() for other valid requests
    // - Prints appropriate messages
};

void processRequest(const string& request, Handler* handler) {
    cout << "Processing: " << request << endl;
    if (!handler->handle(request)) {
        cout << "Request denied.\n" << endl;
    } else {
        cout << "Request approved.\n" << endl;
    }
}

int main() {
    Handler* roleCheck = new RoleCheckHandler();
    Handler* auth = new AuthenticationHandler();

    auth->setNext(roleCheck); // Set the chain: auth -> roleCheck

    processRequest("valid", auth);
    processRequest("invalid", auth);
    processRequest("admin", auth);

    delete auth;
    delete roleCheck;

    return 0;
}