#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class GenericStack
{
protected:
    vector<T> stack;

public:
    explicit GenericStack(size_t initialCapacity)
    {
        stack.reserve(initialCapacity);
    }

    GenericStack() = default;

    void push(const T &element)
    {
        stack.push_back(element);
    }

    T pop()
    {
        if (stack.empty())
        {
            throw out_of_range("Stack is empty");
        }
        T topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    T peek() const
    {
        if (stack.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return stack.back();
    }

    bool isEmpty() const
    {
        return stack.empty();
    }
};

class StringStack : public GenericStack<string>
{
public:
    void push(const string &element)
    {
        if (element.empty())
        {
            cout << "Cannot push an empty string onto the stack." << endl;
            return;
        }
        GenericStack::push(element);
    }

    void concatTopTwo()
    {
        if (stack.size() < 2)
        {
            throw out_of_range("Not enough elements to concatenate");
        }
        string top = pop();
        string secondTop = pop();
        push(secondTop + top);
    }
};

int main()
{
    GenericStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    cout << "Top of intStack: " << intStack.peek() << endl;
    cout << "Popped from intStack: " << intStack.pop() << endl;

    StringStack stringStack;
    stringStack.push("");
    stringStack.push("world!");
    stringStack.push("Hello, ");
    stringStack.concatTopTwo();
    cout << "After concatenation, top of stringStack: " << stringStack.peek() << endl;

    return 0;
}
