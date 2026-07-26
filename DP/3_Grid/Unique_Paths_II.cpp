/*

63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at
the top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 *
109.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1)
      return 0;
    if (obstacleGrid[rows - 1][cols - 1] == 1)
      return 0;

    vector<vector<long long>> dp(rows + 1, vector<long long>(cols + 1, 0));
    dp[rows - 1][cols - 1] = 1;

    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        long long bottom = dp[r + 1][c];
        long long right = dp[r][c + 1];

        if (obstacleGrid[r][c] == 0) {
          if (r == rows - 1 && c == cols - 1)
            continue;

          dp[r][c] = bottom + right;
        }
      }
    }

    return dp[0][0];
  }
};

/*

[0,0,0]
[0,1,0]
[0,0,0]

[1,1,1]
[1,0,1]
[1,1,1]

*/

int main() {

  cout << endl;
  return 0;
}
