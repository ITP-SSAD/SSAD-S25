#include <iostream>
#include <vector>
using namespace std;

// Base class
class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    virtual ~Animal()
    {
        cout << "Animal " << name << "has been destroyed" << endl;
    }

    virtual void makeSound() const = 0;
};

// Intermediate class for land animals
class LandAnimal : virtual public Animal
{
public:
    LandAnimal(string n, int a) : Animal(n, a) {}

    virtual void walk() const = 0;
};

// Intermediate class for water animals
class WaterAnimal : virtual public Animal
{
public:
    WaterAnimal(string n, int a) : Animal(n, a) {}

    virtual void swim() const = 0;
};

// Derived class
class Lion : public LandAnimal
{
public:
    Lion(string n, int a) : LandAnimal(n, a), Animal(n, a) {}

    void makeSound() const override
    {
        cout << name << " says: Roar!" << endl;
    }

    void walk() const override
    {
        cout << name << " is walking." << endl;
    }
};

// Derived class
class Dolphin : public WaterAnimal
{
public:
    Dolphin(string n, int a) : WaterAnimal(n, a), Animal(n, a) {}

    void makeSound() const override
    {
        cout << name << " says: Click!" << endl;
    }

    void swim() const override
    {
        cout << name << " is swimming." << endl;
    }
};

// Multiple Inheritance class
class Frog : public LandAnimal, public WaterAnimal
{
public:
    Frog(string n, int a) : LandAnimal(n, a), WaterAnimal(n, a), Animal(n, a) {}

    void makeSound() const override
    {
        cout << name << " says: Ribbit!" << endl;
    }

    void walk() const override
    {
        cout << name << " is hopping." << endl;
    }

    void swim() const override
    {
        cout << name << " is swimming." << endl;
    }
};

int main()
{
    vector<Animal *> zoo;

    zoo.push_back(new Lion("Leo", 5));
    zoo.push_back(new Dolphin("Dolly", 8));
    zoo.push_back(new Frog("Freddy", 2));

    for (Animal *animal : zoo)
    {
        animal->makeSound();
    }

    // Clean up memory
    for (Animal *animal : zoo)
    {
        delete animal;
    }

    return 0;
}
