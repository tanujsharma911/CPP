/*
 * 673. Number of Longest Increasing Subsequence
 *
 * Input: nums = [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
 */

#include <iostream>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);

    int lis = 0;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[i] < dp[prev] + 1){
                dp[i] = dp[prev] + 1;
                cnt[i] = cnt[prev];
            }
            else if(dp[i] == dp[prev] + 1 && nums[prev] < nums[i])
                cnt[i] += cnt[prev];
        }

        if(dp[i] > lis) lis = dp[i];
    }

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << cnt[i] << " ";
    }
    cout << endl;

    int maxCnt = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == lis){
            maxCnt = maxCnt + cnt[i];
        }
    }

    return maxCnt;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};

    cout << findNumberOfLIS(nums);

    cout << endl;
    return 0;
}


/*
 * nums = [1, 3, 5, 4, 7]
 * dp =   [1, 2, 3, 3, 4]
 * cnt =  [1, 1, 1, 1, 2]
 *
 * nums = [3, 1, 2]
 * dp =   [1, 1, 2]
 * cnt =  [1, 1, 1]
 *
 * nums = [2, 2, 2, 2, 2]
 * dp =   [1, 1, 1, 1, 1]
 * cnt =  [1, 2, 3, 4, 5]
 *
 * nums = [1, 5, 4, 3, 2, 6, 7, 10, 8, 9]
 * dp =   [1, 2, 2, 2, 2, 3, 4,  5, 5, 6]
 * cnt =  [1, 1, 1, 1, 1, 4, 4,  1, 1, 1]
 */
