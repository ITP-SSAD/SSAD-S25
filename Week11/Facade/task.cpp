#include <iostream>

// Light class
class Light {
public:
    void on() {
        std::cout << "Lights are on." << std::endl;
    }
    void off() {
        std::cout << "Lights are off." << std::endl;
    }
};

// Thermostat class
class Thermostat {
public:
    void setTemperature(const std::string& mode) {
        if (mode == "eco") {
            std::cout << "Thermostat is set to eco mode." << std::endl;
        } else if (mode == "comfort") {
            std::cout << "Thermostat is set to a comfortable temperature." << std::endl;
        }
    }
};

// SecurityCamera class
class SecurityCamera {
public:
    void activate() {
        std::cout << "Security cameras activated." << std::endl;
    }
    void deactivate() {
        std::cout << "Security cameras deactivated." << std::endl;
    }
};

// SmartHomeFacade class
class SmartHomeFacade {
    Light light;
    Thermostat thermostat;
    SecurityCamera securityCamera;

public:
    void leavingHome() {
        std::cout << "Activating 'Leaving Home' scenario..." << std::endl;
        light.off();
        thermostat.setTemperature("eco");
        securityCamera.activate();
    }

    void arrivingHome() {
        std::cout << "Activating 'Arriving Home' scenario..." << std::endl;
        light.on();
        thermostat.setTemperature("comfort");
        securityCamera.deactivate();
    }
};

int main() {
    SmartHomeFacade smartHome;
    // Simulate leaving home
    smartHome.leavingHome();
    std::cout << "-----------------------------\n";
    // Simulate arriving home
    smartHome.arrivingHome();

    return 0;
}
