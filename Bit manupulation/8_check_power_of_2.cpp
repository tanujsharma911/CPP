/*

231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (((long) n) & ((long) n - 1)) == 0;
}

int main()
{

    cout << endl;
    return 0;
}