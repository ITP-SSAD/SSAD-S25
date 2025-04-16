#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string isbn;
    double price;
    double tax;
public:
    Book(const std::string& isbn, double price, double tax)
        : isbn(isbn), price(price), tax(tax) {}
    
    std::string getIsbn() const { return isbn; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
};

class Coffee {
private:
    std::string brand;
    double price;
    double tax;
    bool discount;
public:
    Coffee(const std::string& brand, double price, double tax, bool discount)
        : brand(brand), price(price), tax(tax), discount(discount) {}
    
    std::string getBrand() const { return brand; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
    bool isDiscount() const { return discount; }
};

class Tea {
private:
    std::string brand;
    double price;
    double tax;
    bool discount;
public:
    Tea(const std::string& brand, double price, double tax, bool discount)
        : brand(brand), price(price), tax(tax), discount(discount) {}
    
    std::string getBrand() const { return brand; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
    bool isDiscount() const { return discount; }
};


// IStoreItem interface (intended for Visitor pattern)
// Note: In the starter code, none of the concrete classes use this.
class IStoreItem {
public:
    // Intended to later declare a method like:
    // virtual double accept(IStoreVisitor* visitor) = 0;
};


// IStoreVisitor interface (intended for Visitor pattern)
// Note: In the starter code, this is just provided for future use.
class IStoreVisitor {
public:
    // Intended to later declare methods like:
    // virtual double visit(Book &book) = 0;
    // virtual double visit(Tea &tea) = 0;
    // virtual double visit(Coffee &coffee) = 0;
};


// StoreVisitor class with independent cost-calculation methods
// (No Visitor pattern “accept” calls here – todo: change that)
class StoreVisitor {
public:
    double calculateBookCost(const Book& book) {
        return book.getPrice() + book.getTax() * book.getPrice();
    }
    
    double calculateTeaCost(const Tea& tea) {
        double cost = tea.getPrice() + tea.getTax() * tea.getPrice();
        if (tea.isDiscount()) 
            cost -= cost * 0.1;
        return cost;
    }
    
    double calculateCoffeeCost(const Coffee& coffee) {
        double cost = coffee.getPrice() + coffee.getTax() * coffee.getPrice();
        if (coffee.isDiscount()) 
            cost -= cost * 0.15;
        return cost;
    }
};


int main() {
    /*
    std::vector<IStoreItem*> items;
    // items.push_back(new Book("1234", 20.01, 0.08));
    // items.push_back(new Book("5678", 345, 0.08));
    // items.push_back(new Coffee("Espresso", 300, 0.092, false));
    // items.push_back(new Coffee("Starbucks", 400, 0.099, true));
    // items.push_back(new Tea("Curtis", 50, 0.003, true));
    
    IStoreVisitor* visitor = new StoreVisitor(); // Future implementation
    double totalCost = 0;
    for (auto item : items) {
        totalCost += item->accept(visitor); // Method to be implemented by students
    }
    
    std::cout << "Total cost = " << totalCost << std::endl;
    */
    
    std::cout << "Starter code for Visitor Pattern." << std::endl;
    return 0;
}
