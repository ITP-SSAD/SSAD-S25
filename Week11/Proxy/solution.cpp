#include <iostream>
#include <string>

// Document interface
class Document {
public:
    virtual void display() = 0;
    virtual ~Document() {}
};

// RealDocument class
class RealDocument : public Document {
private:
    std::string content;
public:
    RealDocument(const std::string& content) : content(content) {}
    void display() override {
        std::cout << "Displaying Document Content: " << content << std::endl;
    }
};

// SecureDocumentProxy class
class SecureDocumentProxy : public Document {
private:
    RealDocument realDocument;
    std::string userRole;
public:
    SecureDocumentProxy(const std::string& content, const std::string& userRole)
            : realDocument(content), userRole(userRole) {}

    void display() override {
        if (userRole == "admin" || userRole == "manager") {
            realDocument.display();
        } else {
            std::cout << "Access Denied: You do not have permission to view this document." << std::endl;
        }
    }
};

// main function
int main() {
    // Document content
    std::string content = "Sensitive Document: Top Secret";

    // Simulate accessing document with different user roles
    SecureDocumentProxy documentForAdmin(content, "admin");
    SecureDocumentProxy documentForManager(content, "manager");
    SecureDocumentProxy documentForGuest(content, "guest");

    std::cout << "Admin Access:\n";
    documentForAdmin.display();

    std::cout << "\nManager Access:\n";
    documentForManager.display();

    std::cout << "\nGuest Access:\n";
    documentForGuest.display();

    return 0;
}
