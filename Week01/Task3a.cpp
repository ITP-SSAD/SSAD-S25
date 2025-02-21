#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (A[i] == A[j]) flag = 1;
        }
        if (!flag) cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
