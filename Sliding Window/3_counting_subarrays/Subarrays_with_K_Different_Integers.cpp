/*

992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A good array is an array where the number of different integers in that array is
exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int helper(vector<int> &nums, int k) {
    int n = nums.size();

    int r = 0, l = 0, ans = 0;
    unordered_map<int, int> freq;

    for (r = 0; r < n; r++) {
      freq[nums[r]]++;

      while (freq.size() > k) {
        freq[nums[l]]--;

        if (freq[nums[l]] == 0) {
          freq.erase(nums[l]);
        }

        l++;
      }

      ans += r - l + 1;
    }

    return ans;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return helper(nums, k) - helper(nums, k - 1);
  }
};

int main() {

  cout << endl;
  return 0;
}