#include <iostream>
#include <vector>
#include <string>

// Forward declaration for the visitor interface
class IStoreVisitor;

// Base interface for store items
class IStoreItem {
public:
    // Each item must implement an accept method that takes a visitor and returns a computed value.
    virtual double accept(IStoreVisitor* visitor) = 0;
    virtual ~IStoreItem() {}
};

// Forward declarations for the concrete classes.
class Book;
class Coffee;
class Tea;

// Visitor interface with an overload for each concrete type.
class IStoreVisitor {
public:
    virtual double visit(Book &book) = 0;
    virtual double visit(Tea &tea) = 0;
    virtual double visit(Coffee &coffee) = 0;
    virtual ~IStoreVisitor() {}
};

class Book : public IStoreItem {
private:
    std::string isbn;
    double price;
    double tax;
public:
    Book(const std::string& isbn, double price, double tax)
        : isbn(isbn), price(price), tax(tax) {}
        
    const std::string& getIsbn() const { return isbn; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
    
    // Accept method calls the visitor's visit method for a Book.
    double accept(IStoreVisitor* visitor) override {
        return visitor->visit(*this);
    }
};

class Coffee : public IStoreItem {
private:
    std::string brand;
    double price;
    double tax;
    bool discount;
public:
    Coffee(const std::string& brand, double price, double tax, bool discount)
        : brand(brand), price(price), tax(tax), discount(discount) {}
        
    const std::string& getBrand() const { return brand; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
    bool isDiscount() const { return discount; }
    
    // Accept method calls the visitor's visit method for a Coffee.
    double accept(IStoreVisitor* visitor) override {
        return visitor->visit(*this);
    }
};

class Tea : public IStoreItem {
private:
    std::string brand;
    double price;
    double tax;
    bool discount;
public:
    Tea(const std::string& brand, double price, double tax, bool discount)
        : brand(brand), price(price), tax(tax), discount(discount) {}
        
    const std::string& getBrand() const { return brand; }
    double getPrice() const { return price; }
    double getTax() const { return tax; }
    bool isDiscount() const { return discount; }
    
    // Accept method calls the visitor's visit method for a Tea.
    double accept(IStoreVisitor* visitor) override {
        return visitor->visit(*this);
    }
};

class StoreVisitor : public IStoreVisitor {
public:
    // Book cost is price + tax * price.
    double visit(Book &book) override {
        return book.getPrice() + book.getTax() * book.getPrice();
    }
    
    // Tea cost is calculated similarly, but if there is a discount then 10% is deducted.
    double visit(Tea &tea) override {
        double cost = tea.getPrice() + tea.getTax() * tea.getPrice();
        if (tea.isDiscount()) {
            cost -= cost * 0.1;
        }
        return cost;
    }
    
    // Coffee cost is calculated similarly, but if there is a discount then 15% is deducted.
    double visit(Coffee &coffee) override {
        double cost = coffee.getPrice() + coffee.getTax() * coffee.getPrice();
        if (coffee.isDiscount()) {
            cost -= cost * 0.15;
        }
        return cost;
    }
};

int main() {
    // Create a list of store items.
    std::vector<IStoreItem*> items;
    items.push_back(new Book("1234", 20.01, 0.08));
    items.push_back(new Book("5678", 345, 0.08));
    items.push_back(new Coffee("Espresso", 300, 0.092, false));
    items.push_back(new Coffee("Starbucks", 400, 0.099, true));
    items.push_back(new Tea("Curtis", 50, 0.003, true));
    
    // Create the visitor.
    StoreVisitor visitor;
    double totalCost = 0;
    
    // Apply the visitor to each store item.
    for (auto item : items) {
        totalCost += item->accept(&visitor);
    }
    
    std::cout << "Total cost = " << totalCost << std::endl;
    
    // Clean up dynamically allocated items.
    for (auto item : items) {
        delete item;
    }
    
    return 0;
}
