/*
This program computes (a^b) % m using modular exponentiation
(Binary Exponentiation).

- It efficiently calculates large powers under modulo in O(log b) time.
- The algorithm works by recursively dividing the exponent by 2.
- This approach avoids overflow and is commonly used in
  competitive programming and cryptography.

Example:
Input:  a = 5, b = 2, m = 7
Output: (5^2) % 7 = 4
*/

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

    if (b % 2 == 1) // if power is odd, multiply it once more
    {
        u = (u * a) % m;
    }

    return u;
}

int main()
{
    cout << "5^2 mod 7: ";
    cout << modpower(5, 2, 7) << endl;

    return 0;
}
