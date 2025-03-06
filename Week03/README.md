# Week 3

## Task 1: Zoo Animal Hierarchy

**Instructions:**

1. **Base Class `Animal`**
   - Define a base class `Animal` with common attributes like `name` and `age` (protected access modifiers).
   - Include a virtual function `makeSound()` for specific animal sounds.

1. **Intermediate Classes: `LandAnimal` and `WaterAnimal`**

   - Modify `LandAnimal` and `WaterAnimal` to inherit from `Animal`.
   - Add at least one unique method to each (e.g., `walk()` for `LandAnimal` and `swim()` for `WaterAnimal`).
   - Implement the `makeSound()` method in a way that reflects their land/water nature.

1. **Implement Derived Classes**

   - Create classes `Lion` and `Dolphin` that inherit from `LandAnimal` and `WaterAnimal` respectively.
   - Override the unique methods (e.g., `walk()`, `swim()`) and `makeSound()`.

1. **Create a Multiple Inheritance Class**

   - Develop a class to represent an Amphibian (Call it `Frog`) that inherits from both `LandAnimal` and `WaterAnimal`.
   - Resolve any potential ambiguities or issues arising from multiple inheritance.

1. **Demonstrate Polymorphism**

   - In the main function, create a collection of `Animal` pointers.
   - Populate with instances of `Lion`, `Dolphin`, and `Frog`.
   - Iterate through the collection, calling `makeSound()` and the unique methods.

1. **Abstraction Discussion**
   - Discuss how the base class and intermediate classes provide an abstraction layer.

### Expected Output

The program should instantiate various animal types, demonstrating polymorphism with `makeSound()` and the specific behaviors of land and water animals.
