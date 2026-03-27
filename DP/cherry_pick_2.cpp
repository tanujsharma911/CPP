/*
1463. Cherry Pickup II

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j]
represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
*/
#include <iostream>
#include <vector>

using namespace std;

int cherryPickup(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &memo)
{
    int n = grid.size();
    int m = grid[0].size();

    if (c1 < 0 || c1 > m - 1 || c2 < 0 || c2 > m - 1)
    {
        return -1e8;
    }

    if (r == n - 1)
    {
        if (c1 == c2)
        {
            return grid[r][c1];
        }

        return grid[r][c1] + grid[r][c2];
    }

    if (memo[r][c1][c2] != -1)
        return memo[r][c1][c2];

    int pickedCherry = INT_MIN;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            pickedCherry = max(pickedCherry, cherryPickup(r + 1, c1 + i, c2 + j, grid, memo));
        }
    }

    if (c1 == c2)
    {
        pickedCherry += grid[r][c1];
    }
    else
    {
        pickedCherry += grid[r][c1] + grid[r][c2];
    }

    return memo[r][c1][c2] = pickedCherry;
}

int main()
{
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << cherryPickup(0, 0, m - 1, grid, memo) << endl;

    return 0;
}