#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Part 1: Singleton Logger
class Logger {
private:
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const string& message) {
        cout << "Log: " << message << endl;
    }
};

// Part 2: State Pattern - Document States
class DocumentState {
public:
    virtual ~DocumentState() {}
    virtual void handleInput(const string& input) = 0;
};

class DraftState : public DocumentState {
public:
    void handleInput(const string& input) override {
        Logger::getInstance().log("Draft state handling input: " + input);
    }
};

class ReviewState : public DocumentState {
public:
    void handleInput(const string& input) override {
        Logger::getInstance().log("Review state handling input: " + input);
    }
};

class FinalState : public DocumentState {
public:
    void handleInput(const string& input) override {
        Logger::getInstance().log("Final state, no input allowed");
    }
};

// Part 3: Prototype Pattern - Document Cloning
class DocumentPrototype {
public:
    virtual ~DocumentPrototype() {}
    virtual DocumentPrototype* clone() const = 0;
    virtual void print() const = 0;
};

class ReportType : public DocumentPrototype {
    string content;
public:
    ReportType(const string& content) : content(content) {}
    DocumentPrototype* clone() const override {
        Logger::getInstance().log("Cloning ReportType");
        return new ReportType(*this);
    }
    void print() const override {
        cout << "Report Content: " << content << endl;
    }
};

class InvoiceType : public DocumentPrototype {
    string details;
public:
    InvoiceType(const string& details) : details(details) {}
    DocumentPrototype* clone() const override {
        Logger::getInstance().log("Cloning InvoiceType");
        return new InvoiceType(*this);
    }
    void print() const override {
        cout << "Invoice Details: " << details << endl;
    }
};

// Document class integrating State and Prototype patterns
class Document {
    unique_ptr<DocumentState> state;
    unique_ptr<DocumentPrototype> prototype;

public:
    Document(DocumentPrototype* prototype) : prototype(prototype->clone()), state(make_unique<DraftState>()) {}

    void changeState(DocumentState* newState) {
        state.reset(newState);
    }

    void handleInput(const string& input) {
        state->handleInput(input);
    }

    void print() const {
        prototype->print();
    }
};

// Main function to demonstrate system functionality
int main() {
    // Prototype instances
    ReportType reportPrototype("Annual Financial Summary 2023");
    InvoiceType invoicePrototype("Invoice #321 for Consulting Services");

    // Clone and use documents
    Document report(&reportPrototype);
    report.handleInput("Editing Report...");
    report.changeState(new ReviewState());
    report.handleInput("Reviewing Report...");
    report.print();

    Document invoice(&invoicePrototype);
    invoice.handleInput("Editing Invoice...");
    invoice.changeState(new FinalState());
    invoice.handleInput("Finalizing Invoice...");
    invoice.print();

    return 0;
}
