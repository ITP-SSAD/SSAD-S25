# Week 4

## Task 1: Implementing a Basic Bank Account Class

**You are given the following class structure:**

1. **`Account` Class**: Base class representing a bank account.
    * Data members: `accountNumber` (int), `balance` (double), `ownerName` (string).
    * Member functions: Constructor(s), `deposit`, `withdraw`, `getBalance`, `getAccountNumber`, `getOwnerName`.
1. **`SavingsAccount` Class**: Derived class representing a savings account, inheriting from `Account`.

    * Additional data member: `interestRate` (double).
    * Additional member functions: Constructor(s), `calculateInterest`, `getInterestRate`.

**Instructions:**

1. Implement the class structure above, including:
    * Constructor(s) for `Account` and `SavingsAccount` classes
    * All member functions (e.g functions to deposit and withdraw money from the account, ensuring that the balance cannot be negative)
    * The `calculateInterest` member function for the `SavingsAccount` class computes the interest accumulated based on the `interestRate` and performs a deposit to the account balance.
    * Use constant member function where necessary
1. Demonstrate the use of the `this` pointer where necessary.
1. Defaulted constructor: The `Account` class should have a defaulted function for it's default constructor
1. Deleted functions: The `Account` class should have deleted functions for the copy constructor and assignment operator

### Usage

```cpp
int main() {
    SavingsAccount savings(123456, 1000.0, "John Doe", 2.5);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();

    cout << "Account Number: " << savings.getAccountNumber() << endl;
    cout << "Owner's Name: " << savings.getOwnerName() << endl;
    cout << "Current Balance: " << savings.getBalance() << endl;
    cout << "Interest Rate: " << savings.getInterestRate() << "%" << endl;

    return 0;
}
```

## Task 2: Implementing a Shape Hierarchy with Casting Techniques

**You are given the following class structure:**

1. **`Shape` Class**: Base class representing a generic shape.
    * Pure virtual member functions: `area` and `perimeter`.

1. **`Rectangle` Class**: Derived class representing a rectangle.
    * Data members: `width` and `height` (double).
    * Member functions: Constructor, `area`, `perimeter`.

1. **`Circle` Class**: Derived class representing a circle.
    * Data member: `radius` (double).
    * Member functions: Constructor, `area`, `perimeter`.

**Instructions:**

1. Implement the class structure above, including:
    * Constructors for `Rectangle` and `Circle` classes to initialize their dimensions.
    * Virtual functions for `area` and `perimeter` in the `Shape` class and override them in the derived classes.
1. Given an instance of the `const Rectangle` and `Circle` classes, demonstrate the use of static cast to perform type conversions.
    * Suppose we wish to create a const pointer to the `Rectangle` type called `rectPtr` and initialize it with `shape` a pointer to the `Shape` type, how will this be done? (Write your answer below [1])
1. At runtime, check if the type of `shape` a pointer to the `Shape` type changed dynamically into a pointer to the `Circle` type. Print `shape is a Circle` or `shape is not a Circle` depending on the check. (Write your answer below [2])
1. Use const cast to remove the const qualifier from `rectPtr`  (Write your answer below [3])
1. Utilize reinterpret cast to reinterpret the bit pattern of `intValue` variable as a `double`. (Write your answer below [4])

NB: You can use `M_PI` (a constant from `cmath` library)

### Usage

```c++
int main()
{
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);

    Shape *shape = &rectangle;

    // Demonstrate static casting [1]

    // Demonstrate dynamic casting [2]
    
    // Demonstrate const casting [3]

    int intValue = 42;
    // Demonstrate reinterpret casting [4]

    return 0;
}
```
