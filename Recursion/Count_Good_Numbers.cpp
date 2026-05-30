/*

1922. Count Good Numbers

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;

    long long power(long long x, long long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        long long half = power(x, n / 2);

        if (n % 2 == 0)
            return (half * half) % MOD;

        return (((half * half) % MOD) * x) % MOD;
    }
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};

/*

0: [0, 2, 4, 6, 8]
1: [2, 3, 5, 7]
2: [0, 2, 4, 6, 8]


5
5 * 4
5 * 4 * 5
5 * 4 * 5 * 4


*/

int main()
{

    cout << endl;
    return 0;
}