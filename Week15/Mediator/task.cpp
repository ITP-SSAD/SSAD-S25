#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Forward declaration
class SmartHouseMediator;

class Device {
public:
    virtual void sendMessage(const string& message) = 0;
    virtual void receiveMessage(const string& message) = 0;
    // Associate this device with a mediator
    virtual void setMediator(SmartHouseMediator* mediator) = 0;
    virtual ~Device() = default;
};

class MotionSensor : public Device {
public:
    void sendMessage(const string& message) override {
        // TODO: use mediator to broadcast message
    }

    void receiveMessage(const string& message) override {
        cout << "MotionSensor received a " << message
                  << ", the owner will be notified that they expect a visitor\n";
    }

    void setMediator(SmartHouseMediator* med) override {
        // TODO: store the mediator pointer
    }

private:
    SmartHouseMediator* mediator = nullptr;
};

class TemperatureSensor : public Device {
public:
    void sendMessage(const string& message) override {
        // TODO: use mediator to broadcast message
    }

    void receiveMessage(const string& message) override {
        cout << "TemperatureSensor received a " << message
                  << ", the room temperature will be adjusted\n";
    }

    void setMediator(SmartHouseMediator* med) override {
        // TODO: store the mediator pointer
    }

private:
    SmartHouseMediator* mediator = nullptr;
};

class SmartHouseMediator {
public:
    void addDevice(Device* device) {
        // TODO: register device and give it this mediator
    }

    void mediate(Device* sender, const string& message) {
        // TODO: send message to all devices except sender
    }

private:
    vector<Device*> devices;
};

int main() {
    SmartHouseMediator mediator;
    MotionSensor motion;
    TemperatureSensor temp;

    // register devices with the mediator
    // TODO: mediator.addDevice(&motion);
    // TODO: mediator.addDevice(&temp);

    // simulate an event
    motion.sendMessage("Motion detected");

    return 0;
}
