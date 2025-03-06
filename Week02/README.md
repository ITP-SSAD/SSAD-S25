# Week 2

## Task 1

Write a program that contains a class Box.

- Box should have the length, width, and height as member variables.
  - The variables should be of type `unsigned int`.
- Box should have three constructors: default, copy, conversion.
- Box should have the assignment operator.

## Task 2

Add and implement the following member functions to the class Box:

```c++
unsigned getVolume(); // returns the volume of the box.

void scale(unsigned scaleValue); // multiply each side of the box with scaleValue.

bool isBigger(unknown other); // this box is larger than the other (you decide what the type should be)

bool isSmaller(unknown other); // this box is smaller than the other (you decide what the type should be)
```

## Task 3

Add the following operators to the class Box: `*`, `==`

```c++
* // Box with each side of the original box multiplied with an unsigned integer (scale value).

== // returns true if the sides of two boxes are the same (they may be shuffled), false otherwise
```

## Task 4

Add another class `Cube`. Add an operator to convert an object of type `Cube` to object of type `Box`.
