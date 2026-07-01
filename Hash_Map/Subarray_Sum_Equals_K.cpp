/*

560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> map;
    map[0] = 1;
    int currSum = 0;
    int ans = 0;

    for (auto x : nums) {
      currSum += x;

      if (map.count(currSum - k)) {
        ans += map[currSum - k];
      }

      map[currSum]++;
    }

    return ans;
  }
};

/*

arr = [9,  4, 20,  3, 10,  5]
arr = [9, 13, 33, 36, 46, 51]

tar = 33

*/

int main() {

  cout << endl;
  return 0;
}