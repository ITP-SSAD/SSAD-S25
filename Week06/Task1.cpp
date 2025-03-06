#include <iostream>
#include <cstring>

template <typename T>
class Wrapper {
private:
    T value;

public:
    Wrapper(T val) : value(val) {}

    T getValue() const {
        return value;
    }
};

template <>
class Wrapper<const char*> {
private:
    const char* value;

public:
    Wrapper(const char* val) : value(val) {}

    int getValue() const {
        return strlen(value);
    }
};

int main() {
    Wrapper<int> intWrapper(42);
    std::cout << "Wrapped int value: " << intWrapper.getValue() << std::endl;

    Wrapper<const char*> strWrapper("Hello, World!");
    std::cout << "Length of wrapped string: " << strWrapper.getValue() << std::endl;

    return 0;
}
