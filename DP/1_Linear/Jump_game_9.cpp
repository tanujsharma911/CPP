/*

3660. Jump Game IX

You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

- Jump to index j where j > i is allowed only if nums[j] < nums[i].
- Jump to index j where j < i is allowed only if nums[j] > nums[i].

For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.

Example 1:

Input: nums = [2,1,3]
Output: [2,2,3]

Example 2:

Input: nums = [2,3,1]
Output: [3,3,3]

Idea:

If i got max value of right of the index i and min value on right side
I can perform sequence of jump:

If preMax[i] > sufMin, ans[i] = ans[i + 1] -> ans of right 
else (preMax[i] <= sufMin) then preMax[i] -> I can only go to left side

*/

#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n, nums[0]);

        for(int i = 1; i < n; i++){
            preMax[i] = max(nums[i], preMax[i - 1]);
        }

        int sufMin = INT_MAX;
        vector<int> ans = nums;

        for(int i = n - 1; i >= 0; i--){
            if(preMax[i] > sufMin)
                ans[i] = ans[i + 1];
            else
                ans[i] = preMax[i];

            sufMin = min(nums[i], sufMin);
        }

        return ans;
    }
};

int main() {


    cout << endl;
    return 0;
}