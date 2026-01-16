// Check if at least ONE subset exists whose sum is k

#include <iostream>

    using namespace std;

int subsetSumToK(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<vector<bool>> memo(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        memo[i][0] = 1;
    }
    if (nums[0] <= k)
        memo[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nonpick = memo[i - 1][target];

            bool pick = false;
            if (nums[i] <= target)
                pick = memo[i - 1][target - nums[i]];

            memo[i][target] = pick | nonpick;
        }
    }

    return memo[n - 1][k];
}

int main()
{
    vector<int> nums = {3, 2, 7};
    // vector<int> nums = {1, 2, 3, 4};
    int k = 2;

    cout << subsetSumToK(nums, k) << endl;

    return 0;
}