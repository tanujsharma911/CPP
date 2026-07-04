// 2220. Minimum Bit Flips to Convert Number

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        int x = start ^ goal;

        int bitDifference = 0;

        while (x)
        {
            bitDifference++;
            x = x & (x - 1);
        }

        return bitDifference;
    }
};

int main()
{

    cout << endl;
    return 0;
}