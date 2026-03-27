#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int time = 0;

    while (a <= b)
    {
        a = a * 3;
        b = b * 2;
        time++;
    }

    cout << time << endl;

    return 0;
}