/*

239. Sliding Window Maximum (Hard)

Sliding Window, Queue, Monotonic deque

You are given an array of integers nums, there is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k
numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Example 2:
Input: nums = [1], k = 1
Output: [1]

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
    
            deque<int> q;
    
            vector<int> ans;
    
            for(int i = 0; i < n; i++){
                if(!q.empty() && q.front() <= i - k) {
                    q.pop_front();
                }
    
                while(!q.empty() && nums[q.back()] <= nums[i]){
                    q.pop_back();
                }
    
                q.push_back(i);
    
                if(i >= k - 1){
                    ans.push_back(nums[q.front()]);
                }
            }
    
            return ans;
        }
    };

int main() {
    

    cout << endl;
    return 0;
}