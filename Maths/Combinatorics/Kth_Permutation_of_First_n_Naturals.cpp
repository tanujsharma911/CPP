/*

Kth Permutation of First n Naturals

Given two integers n and k, find the k-th permutation sequence of the first n
natural numbers arranged in lexicographical order. Return the answer as a
string.

Examples :

Input: n = 4, k = 3
Output: 1324
Explanation:The permutations in lexicographical order are 1234, 1243, 1324, ...,
so the 3rd permutation is 1324.

Input: n = 3, k = 5 Output: 312 Explanation: The
permutations in lexicographical order are 123, 132, 213, 231, 312, 321, so the
5th permutation is 312.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  string kthPermutation(int n, int k) {
    vector<int> nums;
    int fact = 1;

    for (int i = 1; i < n; i++) {
      fact *= i;
      nums.push_back(i);
    }
    nums.push_back(n);

    k--; // convert to 0-index

    string ans = "";

    while (true) {
      ans += to_string(nums[k / fact]);

      nums.erase(nums.begin() + k / fact);

      if (nums.empty())
        break;

      k %= fact;
      fact /= nums.size();
    }

    return ans;
  }
};

int main() {

  cout << endl;
  return 0;
}
