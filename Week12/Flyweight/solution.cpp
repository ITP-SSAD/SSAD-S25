#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

using namespace std;

// Shared properties (Flyweight)
class FormatType {
private:
    string font;
    int size;
    string color;

public:
    FormatType(const string& f, int s, const string& c) 
        : font(f), size(s), color(c) {}

    void printFormat() const {
        cout << "Format: " << font << ", " << size << "pt, " << color;
    }

    // Needed for unordered_map comparison
    bool operator==(const FormatType& other) const {
        return font == other.font && 
               size == other.size && 
               color == other.color;
    }
};

// Factory to manage shared formats
class FormatFactory {
private:
    unordered_map<string, shared_ptr<FormatType>> formatMap;

    string makeKey(const string& font, int size, const string& color) {
        return font + to_string(size) + color;
    }

public:
    shared_ptr<FormatType> getFormat(const string& font, int size, const string& color) {
        string key = makeKey(font, size, color);

        if (formatMap.find(key) == formatMap.end()) {
            cout << "Creating new format: " << key << endl;
            formatMap[key] = make_shared<FormatType>(font, size, color);
        }

        return formatMap[key];
    }

    void showAllFormats() const {
        cout << "\nCurrently stored formats:\n";
        for (const auto& entry : formatMap) {
            cout << "Key: " << entry.first << " -> ";
            entry.second->printFormat();
            cout << endl;
        }
    }
};

// Individual character with shared formatting
class FormattedChar {
private:
    char symbol;
    shared_ptr<FormatType> format;

public:
    FormattedChar(char c, shared_ptr<FormatType> f) 
        : symbol(c), format(f) {}

    void print() const {
        cout << symbol << " (";
        format->printFormat();
        cout << ")" << endl;
    }
};

int main() {
    FormatFactory formatFactory;

    // Create our document content
    vector<FormattedChar> document;

    // Add formatted characters (notice repeated formats)
    document.emplace_back('H', formatFactory.getFormat("Arial", 12, "Red"));
    document.emplace_back('e', formatFactory.getFormat("Arial", 12, "Red"));
    document.emplace_back('l', formatFactory.getFormat("Arial", 12, "Red"));
    document.emplace_back('l', formatFactory.getFormat("Arial", 12, "Red"));
    document.emplace_back('o', formatFactory.getFormat("Arial", 12, "Red"));
    
    document.emplace_back(' ', formatFactory.getFormat("Times New Roman", 12, "Black"));
    
    document.emplace_back('W', formatFactory.getFormat("Arial", 14, "Blue"));
    document.emplace_back('o', formatFactory.getFormat("Arial", 14, "Blue"));
    document.emplace_back('r', formatFactory.getFormat("Arial", 14, "Blue"));
    document.emplace_back('l', formatFactory.getFormat("Arial", 14, "Blue"));
    document.emplace_back('d', formatFactory.getFormat("Arial", 14, "Blue"));
    
    document.emplace_back('!', formatFactory.getFormat("Arial", 16, "Green"));

    // Print the document
    cout << "\nFormatted Document:\n";
    for (const auto& ch : document) {
        ch.print();
    }

    // Show memory savings
    formatFactory.showAllFormats();
    cout << "\nMemory Benefits:\n";
    cout << "- 12 characters share just 4 format objects\n";
    cout << "- Repeated formats don't consume extra memory\n";
    cout << "- Only store each unique format combination once\n";

    return 0;
}
