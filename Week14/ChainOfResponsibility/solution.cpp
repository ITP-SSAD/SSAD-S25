#include <iostream>
#include <string>
#include <memory>

class Handler {
public:
    virtual ~Handler() {}
    virtual void setNext(Handler* next) = 0;
    virtual bool handle(const std::string& request) = 0;
};

class AbstractHandler : public Handler {
protected:
    Handler* next;

    bool handleNext(const std::string& request) {
        if (next) {
            return next->handle(request);
        }
        return true; // End of chain by default approves
    }

public:
    AbstractHandler() : next(nullptr) {}
    virtual ~AbstractHandler() {}

    void setNext(Handler* next) override {
        this->next = next;
    }

    virtual bool handle(const std::string& request) override {
        return handleNext(request);
    }
};

class AuthenticationHandler : public AbstractHandler {
public:
    bool handle(const std::string& request) override {
        if (request == "valid" || request == "admin") {
            std::cout << "Authentication success." << std::endl;
            return handleNext(request);
        } else {
            std::cout << "Authentication failed." << std::endl;
            return false;
        }
    }
};

class RoleCheckHandler : public AbstractHandler {
public:
    bool handle(const std::string& request) override {
        if (request == "admin") {
            std::cout << "Hello, admin!" << std::endl;
            return true;
        } else {
            std::cout << "Hello, user!" << std::endl;
            return handleNext(request);
        }
    }
};

void processRequest(const std::string& request, Handler* handler) {
    std::cout << "Processing: " << request << std::endl;
    if (!handler->handle(request)) {
        std::cout << "Request denied.\n" << std::endl;
    } else {
        std::cout << "Request approved.\n" << std::endl;
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