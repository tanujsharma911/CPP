/*
3835. Count Subarrays With Cost Less Than or Equal to K (Medium)

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

long long countSubarrays(vector<int>& nums, long long k) {
    int n = nums.size();

    long long cnt = 0;

    deque<int> maxi;
    deque<int> mini;

    int left = 0, right = 0;

    while(right < n){
        if(!maxi.empty() && maxi.front() < left) maxi.pop_front();
        if(!mini.empty() && mini.front() < left) mini.pop_front();

        while(!maxi.empty() && nums[maxi.back()] < nums[right]) maxi.pop_back();
        while(!mini.empty() && nums[mini.back()] > nums[right]) mini.pop_back();

        if(maxi.empty() || nums[maxi.back()] >= nums[right]){
            maxi.push_back(right);
        }
        if(mini.empty() || nums[mini.back()] <= nums[right]){
            mini.push_back(right);
        }

        long long cost = (nums[maxi.front()] - nums[mini.front()]) * (right - left + 1);

        cout << "nums[" << left << "..." << right << "] cost: (" << nums[maxi.front()] << " - " << nums[mini.front()] << ") * " << (right - left + 1) << " = " << cost << endl;

        while(left <= right) {
            long long cost = 1LL * (nums[maxi.front()] - nums[mini.front()]) * (right - left + 1);
            if(cost <= k) break;

            left++;

            if(!maxi.empty() && maxi.front() < left) maxi.pop_front();
            if(!mini.empty() && mini.front() < left) mini.pop_front();
        }

        cnt += right - left + 1;
        right++;
    }

    return cnt;
}

int main()
{
    vector<int> nums = {1,3,2};

    cout << countSubarrays(nums, 4);


    cout << endl;
    return 0;
}
