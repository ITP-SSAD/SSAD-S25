#include <iostream>
#include <memory>

using namespace std;

class Box
{
public:
    int value;
    explicit Box(int v) : value(v)
    {
        cout << "Box created with value: " << value << endl;
    }
    ~Box()
    {
        cout << "Box destroyed with value: " << value << endl;
    }
};

int create_unique(Box &value)
{
    unique_ptr<Box> u1 = make_unique<Box>(value);
    unique_ptr<Box> u2 = move(u1);

    if (!u1)
    {
        cout << "u1 is now null\n";
    }

    return u2.get()->value;
}

void create_shared_boxes()
{
    auto box1 = make_shared<Box>(10);
    {
        auto box2 = make_shared<Box>(20);
        shared_ptr<Box> box3 = box2;
        // At this point, the reference count for box2's object is 2.
        cout << "Inside the block, after creating box3, box2's ref count: " << box2.use_count() << endl;
    }
    // box2 goes out of scope, but box1 is still in scope.
    cout << "Outside the block, box1's ref count: " << box1.use_count() << endl;
}

void demonstrate_weak_ptr()
{
    shared_ptr<Box> sharedBox = make_shared<Box>(30);
    weak_ptr<Box> weakBox = sharedBox;
    // Checking if weakBox is expired
    if (!weakBox.expired())
    {
        // Converting weak_ptr to shared_ptr to access the object
        shared_ptr<Box> tempBox = weakBox.lock();
        cout << "Accessing Box value through weak_ptr: " << tempBox->value << endl;
        // tempBox goes out of scope and gets destroyed here, but sharedBox keeps the object alive
    }
    // Showing the use case of weak_ptr by checking again after sharedBox is reset
    sharedBox.reset();
    if (weakBox.expired())
    {
        cout << "The weak pointer is expired, pointing to no object." << endl;
    }
}

int main()
{
    Box b1(5);
    auto ivalue = create_unique(b1);
    cout << "integer value: " << ivalue << endl;

    create_shared_boxes();

    demonstrate_weak_ptr();

    return 0;
}
