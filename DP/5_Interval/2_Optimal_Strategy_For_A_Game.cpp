/*

Optimal Strategy For A Game

You are given an integer array arr[] of size n. The array elements represent n
coins of values v1, v2, ....vn. You play against an opponent in an alternating
way. In each turn, a player selects either the first or last coin from the row,
removes it from the row permanently, and receives the coin's value. You need to
determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Examples:

Input: arr[] = [5, 3, 7, 10]
Output: 15
Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed
that we cannot get more than 15 by any possible moves.

Input: arr[] = [8, 15, 3, 7]
Output: 22
Explanation: The user collects the maximum value as 22(7 + 15). It is
guaranteed that we cannot get more than 22 by any possible moves.

*/

#include <iostream>
using namespace std;

// Brute force
class Solution {
  public:
    int dfs(int lo, int hi, int turn, vector<int>& nums, vector<vector<vector<int>>>& memo)
    {
        if(lo > hi) return 0;

        if(memo[lo][hi][turn] != -1) return memo[lo][hi][turn];

        int pick_left = dfs(lo + 1, hi, !turn, nums, memo);
        int pick_right = dfs(lo, hi - 1, !turn, nums, memo);
        
        if(turn == 1) return memo[lo][hi][turn] = min(pick_left, pick_right);

        return memo[lo][hi][turn] = max(nums[lo] + pick_left, nums[hi] + pick_right);
    }
    int maximumAmount(vector<int> &nums) {
        int n = nums.size();

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return dfs(0, n - 1, 0, nums, memo);
    }
};

// Better
class Solution2 {
  public:
    int dfs(int lo, int hi, vector<int>& nums, vector<vector<int>>& memo)
    {
        if(lo > hi) return 0;

        if(memo[lo][hi] != -1) return memo[lo][hi];

        int pick_left = nums[lo] + min(dfs(lo + 2, hi, nums, memo), dfs(lo + 1, hi - 1, nums, memo));
        int pick_right = nums[hi] + min(dfs(lo + 1, hi - 1, nums, memo), dfs(lo, hi - 2, nums, memo));

        return memo[lo][hi] = max(pick_left, pick_right);
    }
    int maximumAmount(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> memo(n, vector<int>(n, -1));

        return dfs(0, n - 1, nums, memo);
    }
};

int main() {

  cout << endl;
  return 0;
}
