#include <iostream>

using namespace std;

int modpower(int a, int b, int m)
{
    if (b == 0)
    {
        return 1;
    }

    long long u = modpower(a, b / 2, m);
    u = (u * u) % m;

    if (b % 2 == 1)
    {
        u = (u * a) % m;
    }

    return u;
}

int main()
{
    cout << "ans: ";
    cout << modpower(5, 2, 7) << endl;

    return 0;
}