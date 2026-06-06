/*

Check K-th Bit

Given two positive integer n and  k, check if the kth index bit of n is set or not.
 Note: A bit is called set if it is 1.

Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int convertToBinaryInt(int n)
{
    string ans = "";

    while (n)
    {
        ans = to_string(n % 2) + ans;

        n = n / 2;
    }

    return stoi(ans);
}

bool checkKthBit(int n, int k)
{
    int bin = 1;

    bin = bin << k;

    return (n & bin) != 0;
}

int main()
{
    cout << checkKthBit(500, 3);

    cout << endl;
    return 0;
}