// 2770. Maximum Number of Jumps to Reach the Last Index

#include <iostream>

using namespace std;

class Solution
{
public:
    int helper(int i, vector<int> &nums, int &target, vector<int> &memo)
    {
        int n = nums.size();

        if (i == n - 1)
        {
            return 0;
        }

        if (memo[i] != -1)
            return memo[i];

        int maxJumps = INT_MIN;

        for (int k = i + 1; k < n; k++)
        {
            if (-target <= nums[k] - nums[i] && nums[k] - nums[i] <= target)
            {
                int jumps = 1 + helper(k, nums, target, memo);
                maxJumps = max(maxJumps, jumps);
            }
        }

        return memo[i] = maxJumps;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> memo(n, -1);
        memo[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int maxJumps = INT_MIN;

            for (int k = i + 1; k < n; k++)
            {
                if (-target <= nums[k] - nums[i] && nums[k] - nums[i] <= target)
                {
                    int jumps = 1 + memo[k];
                    maxJumps = max(maxJumps, jumps);
                }
            }

            memo[i] = maxJumps;
        }

        return (memo[0] < 0) ? -1 : memo[0];
    }
};

int main()
{
    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int target = 2;

    Solution s;

    cout << s.maximumJumps(nums, target); // 3

    cout << endl;
    return 0;
}