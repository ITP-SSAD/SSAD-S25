#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < A.size(); i++) {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (A[i] == A[j]) flag = 1;
        }
        if (flag) {
            A.erase(A.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
