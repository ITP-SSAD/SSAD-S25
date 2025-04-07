#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Simple character with formatting - stores all properties individually
class FormattedCharacter {
private:
    char character;
    string font;
    int size;
    string color;

public:
    FormattedCharacter(char c, const string& f, int s, const string& col)
        : character(c), font(f), size(s), color(col) {}

    void print() const {
        cout << "Character: " << character << " with properties: ";
        cout << "Font: " << font << ", Size: " << size << ", Color: " << color << endl;
    }
};

// Client code - creates formatted text
int main() {
    vector<FormattedCharacter> document;

    // Add characters to our document
    document.emplace_back('H', "Arial", 12, "Red");
    document.emplace_back('e', "Arial", 12, "Red");
    document.emplace_back('l', "Arial", 12, "Red");
    document.emplace_back('l', "Arial", 12, "Red");
    document.emplace_back('o', "Arial", 12, "Red");
    
    document.emplace_back(' ', "Times New Roman", 12, "Black");
    
    document.emplace_back('W', "Arial", 14, "Blue");
    document.emplace_back('o', "Arial", 14, "Blue");
    document.emplace_back('r', "Arial", 14, "Blue");
    document.emplace_back('l', "Arial", 14, "Blue");
    document.emplace_back('d', "Arial", 14, "Blue");
    
    document.emplace_back('!', "Arial", 16, "Green");

    // Print all characters
    cout << "Document content:\n";
    for (const auto& fc : document) {
        fc.print();
    }

    // Memory analysis
    cout << "\nMemory Usage Analysis:\n";
    cout << "Total characters: " << document.size() << endl;
    cout << "Each character stores its own properties (font, size, color)\n";
    cout << "This is inefficient when many characters share the same formatting!\n";

    return 0;
}
