#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Interface
class ITransport {
public:
    virtual void deliver() = 0;
    virtual ~ITransport() = default;
};

// Concrete implementations
class Truck : public ITransport {
private:
    string address;
    
public:
    explicit Truck(const string& addr) : address(addr) {}
    
    void deliver() override {
        cout << "Delivering by truck to address: " << address << endl;
    }
};

class Ship : public ITransport {
private:
    string country;
    
public:
    explicit Ship(const string& cntry) : country(cntry) {}
    
    void deliver() override {
        cout << "Delivering by ship to country: " << country << endl;
    }
};

class Plane : public ITransport {
private:
    string country;
    
public:
    explicit Plane(const string& cntry) : country(cntry) {}
    
    void deliver() override {
        cout << "Delivering by plane to country: " << country << endl;
    }
};

// Factory class
class TransportFactory {
public:
    enum class TransportType { TRUCK, SHIP, PLANE };
    
    static unique_ptr<ITransport> getTransport(TransportType type, const string& destination) {
        switch(type) {
            case TransportType::TRUCK:
                return make_unique<Truck>(destination);
            case TransportType::SHIP:
                return make_unique<Ship>(destination);
            case TransportType::PLANE:
                return make_unique<Plane>(destination);
            default:
                throw invalid_argument("Unknown transport type");
        }
    }
};

int main() {
    // Create different transports using the factory
    auto truck = TransportFactory::getTransport(
        TransportFactory::TransportType::TRUCK, "123 Main St, New York");
    auto ship = TransportFactory::getTransport(
        TransportFactory::TransportType::SHIP, "Japan");
    auto plane = TransportFactory::getTransport(
        TransportFactory::TransportType::PLANE, "Australia");
        
    // Use the transports
    truck->deliver();
    ship->deliver();
    plane->deliver();
    return 0;
}