/*

523. Continuous Subarray Sum

Given an integer array nums and an integer k, return true if nums has a good
subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n *
k. 0 is always a multiple of k.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int>
        remainder_first_seen; // preffix remainder -> first occurrence position
    remainder_first_seen[0] = -1;

    int currSum = 0;
    for (int i = 0; i < n; i++) {
      currSum += nums[i];

      if (remainder_first_seen.count(currSum % k)) {
        if (i - remainder_first_seen[currSum % k] > 1) {
          return true;
        }
      } else {
        remainder_first_seen[currSum % k] = i;
      }
    }

    return false;
  }
};
/*

k = 6, 12, 18, 24, 30

nums    = 23, 2, 4, 6, 7

for i = 0:
    currSum = 23
    remainder_first_seen = {
        0 = -1,
        5 = 0
    }

for i = 1:
    currSum = 25
    remainder_first_seen = {
        0 = -1,
        5 = 0,
        1 = 1
    }

for i = 2:
    We found [currSum % k] already in remainder_first_seen

------------------------------------------------------

k = 7, 14, 21, 28, 35

nums   = (23,  2,  4,  6),  6
prefix = 23, 25, 29, 35, 41


*/

int main() {

  cout << endl;
  return 0;
}