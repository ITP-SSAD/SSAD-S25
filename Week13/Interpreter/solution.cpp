#include <iostream>
#include <memory>
#include <vector>

// Forward declaration
class Expression;

// Alias for shared pointers to expressions
using ExpressionPtr = std::shared_ptr<Expression>;

// Abstract base class for all expressions
class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;
};

// Terminal expression for numbers
class NumberExpression : public Expression {
    double value;
public:
    explicit NumberExpression(double val) : value(val) {}
    double evaluate() const override { return value; }
};

// Non-terminal expression for addition
class AddExpression : public Expression {
    ExpressionPtr left;
    ExpressionPtr right;
public:
    AddExpression(ExpressionPtr l, ExpressionPtr r) : left(l), right(r) {}
    double evaluate() const override { 
        return left->evaluate() + right->evaluate(); 
    }
};

// Non-terminal expression for subtraction
class SubtractExpression : public Expression {
    ExpressionPtr left;
    ExpressionPtr right;
public:
    SubtractExpression(ExpressionPtr l, ExpressionPtr r) : left(l), right(r) {}
    double evaluate() const override { 
        return left->evaluate() - right->evaluate(); 
    }
};

// Non-terminal expression for multiplication
class MultiplyExpression : public Expression {
    ExpressionPtr left;
    ExpressionPtr right;
public:
    MultiplyExpression(ExpressionPtr l, ExpressionPtr r) : left(l), right(r) {}
    double evaluate() const override { 
        return left->evaluate() * right->evaluate(); 
    }
};

// Helper function to create number expressions
ExpressionPtr number(double value) {
    return std::make_shared<NumberExpression>(value);
}

// Helper function to create addition expressions
ExpressionPtr add(ExpressionPtr left, ExpressionPtr right) {
    return std::make_shared<AddExpression>(left, right);
}

// Helper function to create subtraction expressions
ExpressionPtr subtract(ExpressionPtr left, ExpressionPtr right) {
    return std::make_shared<SubtractExpression>(left, right);
}

// Helper function to create multiplication expressions
ExpressionPtr multiply(ExpressionPtr left, ExpressionPtr right) {
    return std::make_shared<MultiplyExpression>(left, right);
}

int main() {
    // Build the expression: (5 + 3) * (10 - 4)
    // Which should evaluate to 48
    
    ExpressionPtr expr = multiply(
        add(number(5), number(3)),
        subtract(number(10), number(4))
    );
    
    std::cout << "Expression: (5 + 3) * (10 - 4)\n";
    std::cout << "Result: " << expr->evaluate() << std::endl;
    
    // More complex expression: 2 * (3 + 5) - 8
    // Should evaluate to 8
    
    ExpressionPtr complexExpr = subtract(
        multiply(
            number(2),
            add(number(3), number(5))
        ),
        number(8)
    );
    
    std::cout << "\nExpression: 2 * (3 + 5) - 8\n";
    std::cout << "Result: " << complexExpr->evaluate() << std::endl;
    
    return 0;
}