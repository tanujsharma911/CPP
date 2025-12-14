#include <iostream>

using namespace std;

int main()
{
    int cubes;
    cin >> cubes;

    int levels = 0;

    while (cubes >= ((levels + 1) * (levels + 2)) / 2)
    {
        levels++;
        cubes -= (levels * (levels + 1)) / 2;
    }

    cout << levels << endl;

    return 0;
}