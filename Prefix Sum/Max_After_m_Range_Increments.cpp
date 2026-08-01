/*

Max After m Range Increments

Given three arrays a[], b[], and k[], representing m range increment operations
on an array arr[] of size n, where all elements of arr[] are initially 0.

Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j
≤ b[i] (mainly indexes in range from a[i] to b[i]) After performing all the
given operations, find the maximum value present in the array.

Examples:

Input: n = 5, a[] = [0, 1, 2], b[] = [1, 4, 3], k[] = [100, 100, 100]
Output: 200
Explanation: Initially, arr = [0, 0, 0, 0, 0]
After the first operation: arr = [100, 100, 0, 0, 0]
After the second operation: arr = [100, 200, 100, 100, 100]
After the third operation: arr = [100, 200, 200, 200, 100]
The maximum element after all operations is 200.

Input: n = 4, a[] = [1, 0, 3], b[] = [2, 0, 3], k[] = [603, 286, 882]
Output: 882
Explanation: Initially, arr = [0, 0, 0, 0]
After the first operation: arr = [0, 603, 603, 0]
After the second operation: arr = [286, 603, 603, 0]
After the third operation: arr = [286, 603, 603, 882]
The maximum element after all operations is 882.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int findMax(int n, vector<int> &a, vector<int> &b, vector<int> &k) {
    vector<int> ans(n + 1, 0);

    for (int i = 0; i < a.size(); i++) {
      int st = a[i];
      int end = b[i];
      int val = k[i];

      ans[st] += val;
      ans[end + 1] -= val;
    }

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
      ans[i + 1] += ans[i];

      maxi = max(maxi, ans[i]);
    }

    return maxi;
  }
};

int main() {

  cout << endl;
  return 0;
}
