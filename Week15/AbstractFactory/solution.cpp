#include <iostream>
using namespace std;

// Abstract product interfaces
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() = default;
};

// Concrete products for Windows
class WinButton : public Button {
public:
    void render() override {
        cout << "Rendering Windows Button" << endl;
    }
};

class WinCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering Windows Checkbox" << endl;
    }
};

// Concrete products for Mac
class MacButton : public Button {
public:
    void render() override {
        cout << "Rendering Mac Button" << endl;
    }
};

class MacCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering Mac Checkbox" << endl;
    }
};

// Abstract factory interface
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete factory for Windows
class WinFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WinButton();
    }
    
    Checkbox* createCheckbox() override {
        return new WinCheckbox();
    }
};

// Concrete factory for Mac
class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

// Application class that uses the factory
class Application {
private:
    GUIFactory* factory;
    Button* button;
    Checkbox* checkbox;
    
public:
    Application(GUIFactory* f) : factory(f) {
        button = factory->createButton();
        checkbox = factory->createCheckbox();
    }

    void paint() {
        button->render();
        checkbox->render();
    }
};

// Client code to test the pattern
int main() {
    // Assume we are on Windows
    GUIFactory* factory = new WinFactory();
    Application* app = new Application(factory);
    app->paint();
    
    // Clean up
    delete app;
    delete factory;

    // Assume we are on Mac
    factory = new MacFactory();
    app = new Application(factory);
    app->paint();

    // Clean up
    delete app;
    delete factory;

    return 0;
}
