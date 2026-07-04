
/*

137. Single Number II

every element appears three times except for one

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int bitIdx = 0; bitIdx < 32; bitIdx++)
        {
            int once = 0;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] & (1 << bitIdx))
                {
                    once++;
                }
            }

            if (once % 3 == 1)
            {
                ans = ans | (1 << bitIdx);
            }
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}