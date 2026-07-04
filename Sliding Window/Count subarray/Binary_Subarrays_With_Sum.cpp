/*

930. Binary Subarrays With Sum (Medium)

You are given a binary array nums and an integer goal.

A subarray is a contiguous part of the array.

Return the number of non-empty subarrays with a sum goal.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[(1,0,1),0,1]
[(1,0,1,0),1]
[1,(0,1,0,1)]
[1,0,(1,0,1)]

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int helper(vector<int> &nums, int goal) {
    int n = nums.size();

    int l = 0, r = 0, currSum = 0, cnt = 0;

    while (r < n) {
      currSum += nums[r];

      while (l <= r && currSum > goal) {
        currSum -= nums[l];
        l++;
      }

      cnt += r - l + 1;
      r++;
    }

    return cnt;
  }
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return helper(nums, goal) - helper(nums, goal - 1);
  }
};

/*

goal = 2
nums = [1,0,1,0,1]
prefixSumCount = {
    0: 1
    1: 2
    2: 2
    3: 1

}

For i = 0:

    currentSum - goal >= 0:
        result += prefixSumCount[currentSum - goal];

*/

int main() {
  Solution s;

  vector<int> nums = {1, 0, 1, 0, 1};

  cout << s.numSubarraysWithSum(nums, 2);

  cout << endl;
  return 0;
}