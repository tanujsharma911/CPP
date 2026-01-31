/*
 * Longest Increasing Subsequence
 *
 * Given an integer array nums, return the length of the longest
 * strictly increasing subsequence.
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 */

#include <iostream>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> memo(n + 1, 0), curr(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        for(int last = i - 1; last >= -1; last--){

            int len = memo[last + 1];

            if(last == -1 || nums[last] < nums[i])
            {
                len = max(len, memo[i + 1] + 1);
            }

            curr[last + 1] = len;
        }
        memo = curr;
    }

    return memo[0];
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << lengthOfLIS(nums);

    cout << endl;
    return 0;
}
