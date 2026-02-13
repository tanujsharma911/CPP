/*
 * 239. Sliding Window Maximum (Hard)
 *
 * Sliding Window, Queue, Monotonic deque
 *
 * You are given an array of integers nums, there is a sliding window of size k which is
 * moving from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.
 *
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 *
 * Example 2:
 * Input: nums = [1,3,1,2,0,5], k = 3
 * Output: [3,3,2,5]
 *
 * Example 2:
 * Input: nums = [-7,-8,7,5,7,1,6,0], k = 4
 * Output: [7,7,7,7,7]
 */

#include <deque>
#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    deque<int> q;
    vector<int> ans;

    q.push_back(0);

    for(int i = 0; i < k; i++){
        while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();

        if(q.empty() || nums[q.back()] > nums[i])
            q.push_back(i);
    }

    ans.push_back(nums[q.front()]);

    for(int i = k; i < n; i++){
        if(!q.empty() && q.front() <= i - k) q.pop_front();

        while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();

        if(q.empty() || nums[q.back()] >= nums[i])
            q.push_back(i);

        ans.push_back(nums[q.front()]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(auto it: ans){
        cout << it << " ";
    }

    cout << endl;
    return 0;
}
