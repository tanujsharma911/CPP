/*

50. Pow(x, n)

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    unordered_map<long, double> memo;

    double helper(double x, long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        if (memo.count(n))
            return memo[n];

        if (n % 2 == 0)
            return memo[n] = helper(x, n / 2) * helper(x, n / 2);
        else
            return memo[n] = helper(x, n / 2) * helper(x, n / 2) * x;
    }
    double myPow(double x, int n)
    {
        if (n >= 0)
            return helper(x, n);
        else
            return 1.0 / helper(x, abs((long)n));
    }
};

/*

2^10
2^5 * 2^5
2^5 * 2^3 * 2^2
2^5 * 2^3 * 2 * 2

*/

int main()
{

    cout << endl;
    return 0;
}