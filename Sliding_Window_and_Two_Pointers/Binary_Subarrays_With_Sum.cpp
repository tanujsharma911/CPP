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
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();

    int result = 0;

    vector<int> prefix_sum(n, 0);

    prefix_sum[0] = nums[0];

    for (int i = 1; i < n; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }

    for (int i = 0; i < n; i++) {

      for (int j = i; j < n; j++) {

        if (prefix_sum[i] - prefix_sum[j] == goal) {
          result++;
        }
      }
    }

    return result;
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