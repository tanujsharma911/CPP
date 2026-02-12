/*
3835. Count Subarrays With Cost Less Than or Equal to K

You are given an integer array nums, and an integer k.

For any subarray nums[l..r], define its cost as:
cost = (max(nums[l..r]) - min(nums[l..r])) * (r - l + 1).

Return an integer denoting the number of subarrays of nums whose cost is less than or equal to k.

Example 1:
Input: nums = [1,3,2], k = 4
Output: 5

Example 2:
Input: nums = [5,5,5,5], k = 0
Output: 10

Example 3:
Input: nums = [1,2,3], k = 0
Output: 3
*/

#include <iostream>
using namespace std;

long long countSubarrays_BruteForce(vector<int>& nums, long long k) {
    int n = nums.size();

    long long cnt = 0;

    for(int i = 0; i < n; i++){
        int maxi = -1e9, mini = 1e9;

        for(int j = i; j < n; j++){
            maxi = max(maxi, nums[j]);
            mini = min(mini, nums[j]);

            if((maxi - mini) * 1LL * (j - i + 1) <= k){
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    
    
    
    cout << endl;
    return 0;
}