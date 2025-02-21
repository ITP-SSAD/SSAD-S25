#include <iostream>

using namespace std;

int main()
{
    int time;
    cin >> time;

    int seconds = time % 60;
    int minutes = (time / 60) % 60;
    int hours = time / 3600;

    cout << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}
