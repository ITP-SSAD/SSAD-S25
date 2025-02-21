#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override
    {
        return width * height;
    }

    double perimeter() const override
    {
        return 2 * (width + height);
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);

    // Static cast
    Shape *shape = &rectangle;
    Rectangle *rectPtr = static_cast<Rectangle *>(shape);

    // Dynamic cast
    if (dynamic_cast<Circle *>(shape) != nullptr)
    {
        std::cout << "Shape is a Circle." << std::endl;
    }
    else
    {
        std::cout << "Shape is not a Circle." << std::endl;
    }

    // Const cast
    double area = const_cast<Rectangle *>(rectPtr)->area();

    // Reinterpret cast
    int intValue = 42;
    double doubleValue = reinterpret_cast<double &>(intValue);

    return 0;
}