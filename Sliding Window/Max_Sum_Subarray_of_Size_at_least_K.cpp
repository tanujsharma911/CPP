/*

Max Sum Subarray of Size at least K

Given an array arr[] and an integer k, find the maximum sum among all contiguous
subarrays having a length greater than or equal to k.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int maxSumWithK(vector<int> &arr, int k) {
    int n = arr.size();

    int windowSum = 0, maxSum = INT_MIN, extend = 0;

    for (int i = 0; i < k; i++)
      windowSum += arr[i];

    maxSum = windowSum;

    for (int i = k; i < n; i++) {
      windowSum += arr[i] - arr[i - k];

      extend = max(0, extend + arr[i - k]);

      maxSum = max(maxSum, extend + windowSum);
    }

    return maxSum;
  }
};

int main() {

  cout << endl;
  return 0;
}
