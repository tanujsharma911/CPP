/*

877. Stone Game

Alice and Bob play a game with piles of stones. There are an even number of
piles arranged in a row, and each pile has a positive integer number of stones
piles[i].

The objective of the game is to end with the most stones. The total number of
stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes
the entire pile of stones either from the beginning or from the end of the row.
This continues until there are no more piles left, at which point the person
with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or
false if Bob wins.

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation:
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10
points. If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to
win with 9 points. This demonstrated that taking the first 5 was a winning move
for Alice, so we return true.

Example 2:

Input: piles = [3,7,2,3]
Output: true

*/

#include <iostream>
using namespace std;

class Solution {
public:
  // brute force
  int dfs(int lo, int hi, vector<int> &piles, vector<vector<int>> &dp) {
    if (lo > hi) {
      return 0;
    }

    if (dp[lo][hi] != -1)
      return dp[lo][hi];

    int pick_left = piles[lo] - dfs(lo + 1, hi, piles, dp);
    int pick_right = piles[hi] - dfs(lo, hi - 1, piles, dp);

    return dp[lo][hi] = max(pick_left, pick_right);
  }
  bool stoneGame1(vector<int> &piles) {
    int n = piles.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return dfs(0, n - 1, piles, dp) > 0;
  }

  // better
  int solve(int i, vector<int> &piles, vector<int> &dp) {
    int n = piles.size();

    if (i >= n)
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int not_pick = solve(i + 1, piles, dp);
    int pick = piles[i] + solve(i + 2, piles, dp);

    return dp[i] = max(not_pick, pick);
  }
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();

    int total_stones = 0;
    for (auto pile : piles)
      total_stones += pile;

    vector<int> dp(n, -1);

    int p1 = solve(0, piles, dp);

    return p1 > (total_stones - p1);
  }
};

int main() {

  cout << endl;
  return 0;
}
