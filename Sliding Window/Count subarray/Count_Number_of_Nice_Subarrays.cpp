/*

1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is
called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int helper(vector<int> &nums, int k) {
    if (k < 0)
      return 0;

    int n = nums.size();

    int left = 0, right = 0;
    int odds = 0;
    int ans = 0;

    for (right = 0; right < n; right++) {
      odds += nums[right] % 2;

      while (odds > k) {
        odds -= nums[left] % 2;
        left++;
      }

      ans += right - left + 1;
    }

    return ans;
  }
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    return helper(nums, k) - helper(nums, k - 1);
  }
};

int main() {

  cout << endl;
  return 0;
}