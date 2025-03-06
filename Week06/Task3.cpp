#include <iostream>
#include <vector>

using namespace std;

vector<int> customMap(const vector<int>& vec, int (*func)(int)) {
    vector<int> result;
    for (int elem : vec) {
        result.push_back(func(elem));
    }
    return result;
}

vector<int> customFilter(const vector<int>& vec, bool (*pred)(int)) {
    vector<int> result;
    for (int elem : vec) {
        if (pred(elem)) {
            result.push_back(elem);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    auto squared = customMap(nums, [](int x) { return x * x; });
    cout << "Squared elements: ";
    for (int x : squared) {
        cout << x << " ";
    }
    cout << endl;

    auto odds = customFilter(nums, [](int x) { return x % 2 != 0; });
    cout << "Odd elements: ";
    for (int x : odds) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}