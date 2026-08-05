/*

Subarrays with Sum in Range

Given an integer array arr[] and two integers l and r, find the number of
subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.

Examples:

Input: l = 3, r = 8, arr[] = [1, 4, 6]
Output: 3
Explanation: The subarrays are [1,4], [4] and [6]. Therefore answer for this
test case is 3.


Input: l = 4, r = 13, arr[] = [2, 3, 5, 8] Output: 6
Explanation: The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8].
Therefore answer for this test case is 6.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int atMost(int x, vector<int> &arr) {
    int n = arr.size();

    int st = 0, end = 0;
    int curr_sum = 0, ans = 0;

    for (end = 0; end < n; end++) {
      curr_sum += arr[end];

      while (curr_sum > x) {
        curr_sum -= arr[st];
        st++;
      }

      ans += end - st + 1;
    }

    return ans;
  }
  int countSubarray(vector<int> &arr, int l, int r) {
    int n = arr.size();

    return atMost(r, arr) - atMost(l - 1, arr);
  }
};

int main() {

  cout << endl;
  return 0;
}
