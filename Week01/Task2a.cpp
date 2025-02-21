#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 3, y = 5;

    cout << "Before swapping: " << endl;
    cout << "a = " << x << "; b = " << y << endl;

    swap(&x, &y);

    cout << "After swapping: " << endl;
    cout << "a = " << x << "; b = " << y << "\n";

    return 0;
}
