// 78. Subsets

#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();

    int subsets = 1 << n; // pow(2, n)

    vector<vector<int>> ans;

    for (int i = 0; i < subsets; i++) {
      vector<int> subset;

      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          subset.push_back(nums[j]);
        }
      }

      ans.push_back(subset);
    }

    return ans;
  }
};

/*

nums = {1, 2, 3}, n = 3

subsets = 1 << 3 = 8

i	Binary	 Subset
0	000	{}
1	001	{1}
2	010	{2}
3	011	{1, 2}
4	100	{3}
5	101	{1, 3}
6	110	{2, 3}
7	111	{1, 2, 3}

output = {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}

*/

int main() {

  cout << endl;
  return 0;
}