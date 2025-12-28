#include <iostream>

using namespace std;

bool divisible(const string &s, int k)
{
    int rem = 0;
    for (char c : s)
    {
        rem = (rem * 10 + (c - '0')) % k;
    }
    return rem == 0;
}

int main()
{
    string s = "";

    cout << "Give any positive integer and i will give you it is divisible by: ";
    cin >> s;

    int n = s.length();

    if (s.length() <= 1)
    {
        cout << "Do it by your self" << endl;
    }
    else if (s[0] == '-')
    {
        cout << "Negative not allowed" << endl;
    }
    else
    {
        bool isDivisible = false;
        if (divisible(s, 2))
        {
            cout << "Divisible by 2" << endl;
            isDivisible = true;
        }
        if (divisible(s, 3))
        {
            cout << "Divisible by 3" << endl;
            isDivisible = true;
        }
        if (divisible(s, 5))
        {
            cout << "Divisible by 5" << endl;
            isDivisible = true;
        }
        if (divisible(s, 7))
        {
            cout << "Divisible by 7" << endl;
            isDivisible = true;
        }

        if (!isDivisible)
        {
            cout << "Not divisible by 2, 3, 5 & 7" << endl;
        }
    }

    return 0;
}