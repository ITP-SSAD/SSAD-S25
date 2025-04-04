#include <iostream>
#include <memory>
#include <string>

// Text interface
class Text {
public:
    virtual std::string write() const = 0;
    virtual ~Text() {}
};

// PlainText class
class PlainText : public Text {
private:
    std::string text;
public:
    PlainText(const std::string& text) : text(text) {}
    std::string write() const override {
        return text;
    }
};

// TextDecorator abstract class
class TextDecorator : public Text {
protected:
    std::shared_ptr<Text> wrappedText;
public:
    TextDecorator(std::shared_ptr<Text> text) : wrappedText(text) {}
    virtual std::string write() const override {
        return wrappedText->write();
    }
};

// Bold decorator
class Bold : public TextDecorator {
public:
    Bold(std::shared_ptr<Text> text) : TextDecorator(text) {}
    std::string write() const override {
        // ANSI escape code for bold text
        return "\033[1m" + TextDecorator::write() + "\033[0m";
    }
};

// Italic decorator
class Italic : public TextDecorator {
public:
    Italic(std::shared_ptr<Text> text) : TextDecorator(text) {}
    std::string write() const override {
        // ANSI escape code for italic text
        return "\033[3m" + TextDecorator::write() + "\033[0m";
    }
};

// Underline decorator
class Underline : public TextDecorator {
public:
    Underline(std::shared_ptr<Text> text) : TextDecorator(text) {}
    std::string write() const override {
        // ANSI escape code for underline text
        return "\033[4m" + TextDecorator::write() + "\033[0m";
    }
};

int main() {
    // Plain text
    std::shared_ptr<Text> plainText = std::make_shared<PlainText>("Hello, World!");

    // Adding decorators dynamically
    std::shared_ptr<Text> boldText = std::make_shared<Bold>(plainText);
    std::shared_ptr<Text> italicBoldText = std::make_shared<Italic>(boldText);
    std::shared_ptr<Text> underlinedItalicBoldText = std::make_shared<Underline>(italicBoldText);

    // Display styled text
    std::cout << plainText->write() << std::endl;
    std::cout << boldText->write() << std::endl;
    std::cout << italicBoldText->write() << std::endl;
    std::cout << underlinedItalicBoldText->write() << std::endl;

    return 0;
}
