// 29. Divide Two Integers without divide operator

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (dividend == divisor)
            return 1;

        int sign = 1;
        int quotient = 0;

        bool isQuotientNegative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

        if (isQuotientNegative)
        {
            sign = -1;
        }

        long numerator = abs((long)dividend);
        long denominator = abs((long)divisor);

        while (numerator >= denominator)
        {
            int power = 0;

            while ((denominator << (power + 1)) <= numerator)
            {
                power++;
            }

            numerator -= (denominator << power);
            quotient += (1 << power);
        }

        if (quotient == (1 << 31) && sign)
        {
            return INT_MAX;
        }

        if (quotient == (1 << 31) && !sign)
        {
            return INT_MIN;
        }

        return sign * quotient;
    }
};

int main()
{

    cout << endl;
    return 0;
}