/*

Pairs with Less Than K Diff

Given an array arr[] of positive integers and an integer k, find the total
number of pairs of elements that have an absolute difference strictly less than
k.

Note:  Pair (i, j) is considered the same as (j, i).

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int countPairs(vector<int> arr, int k) {
    int n = arr.size();

    if (n < 2)
      return 0;

    sort(arr.begin(), arr.end());

    int left = 0, pairs = 0;

    for (int right = 1; right < n; right++) {
      while (left < right && abs(arr[left] - arr[right]) >= k) {
        left++;
      }

      if (left != right)
        pairs += right - left;
    }

    return pairs;
  }
};

int main() {

  cout << endl;
  return 0;
}
