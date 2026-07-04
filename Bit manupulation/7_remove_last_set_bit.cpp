/*

Remove the last set (right most 1 bit) bit

Example: n = 16

16 : 1 0 0 0 0
15 : 0 1 1 1 1

16 & 15 : 0 0 0 0

Ans: 0

Example: n = 40

40 : 1 0 1 0 0 0
39 : 1 0 0 1 1 1

40 & 39 : 1 0 0 0 0 0

Ans: 32

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int removeLastSetBit(int n)
{
    return n & (n - 1);
}

int main()
{
    cout << removeLastSetBit(40);

    cout << endl;
    return 0;
}