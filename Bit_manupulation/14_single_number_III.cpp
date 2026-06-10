/*

260. Single Number III

exactly two elements appear only once and all the other elements appear exactly twice

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 2)
            return nums;

        long diff = 0;

        for (auto num : nums)
        {
            diff = diff ^ num;
        }

        diff = (diff & (diff - 1)) ^ diff;

        int b1 = 0; // set bits on diff position
        int b2 = 0; // non set bits on diff position

        for (auto num : nums)
        {
            if (num & diff)
            {
                b1 = b1 ^ num;
            }
            else
            {
                b2 = b2 ^ num;
            }
        }

        return {b1, b2};
    }
};

int main()
{

    cout << endl;
    return 0;
}