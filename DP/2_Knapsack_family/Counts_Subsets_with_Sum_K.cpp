// Count the number of subsets whose sum is exactly k

#include <iostream>

using namespace std;

// int cntSubsetSumToK(int i, vector<int> &nums, int k)
// {
//     int n = nums.size();

//     if (i == 0)
//     {
//         if(k == 0 && nums[0] == k) return 2;
//         if(k == 0 || nums[0] == k) return 1;
//         return 0;
//     }

//     int nonpick = cntSubsetSumToK(i - 1, nums, k);
//     int pick = 0;

//     if (k >= nums[i])
//         pick = cntSubsetSumToK(i - 1, nums, k - nums[i]);

//     return nonpick + pick;
// }

int cntSubsetSumToK(vector<int> &nums, int k)
{
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

    return memo[k];
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int k = 3;

    cout << cntSubsetSumToK(nums, k) << endl;

    return 0;
}