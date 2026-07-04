/*

Count Set Bits

Input: n = 6
Output: 2
Explanation: Binary representation is '110', so the count of the set bit is 2.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

void removeLastSetBit(int &n)
{
    n = n & (n - 1);
}
int setBits(int n)
{
    int cnt = 0;

    while (n)
    {
        cnt++;
        removeLastSetBit(n);
    }

    return cnt;
}

int main()
{

    cout << endl;
    return 0;
}