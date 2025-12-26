#include <iostream>

using namespace std;

int cntSubsetSumToK(int i, vector<int> &nums, int k)
{
    int n = nums.size();

    if (k == 0)
        return 1;
    if (i == 0)
    {
        return nums[i] == k;
    }

    int nonpick = cntSubsetSumToK(i - 1, nums, k);
    int pick = 0;

    if (k >= nums[i])
        pick = cntSubsetSumToK(i - 1, nums, k - nums[i]);

    return nonpick + pick;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    // vector<int> nums = {1, 2, 3, 4, 5, 2, -1};
    int k = 3;

    int n = nums.size();

    vector<int> memo(k + 1, 0);

    memo[0] = 1;

    if (nums[0] <= k)
        memo[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
        for (int target = 0; target <= k; target++)
        {

            int nonpick = memo[target];
            int pick = 0;

            if (target >= nums[i])
                pick = memo[target - nums[i]];

            curr[target] = nonpick + pick;
        }
        memo = curr;
    }

    cout << memo[k] << endl;

    return 0;
}