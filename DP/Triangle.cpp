/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally,
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/

#include <iostream>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[n - 1].size();

    vector<int> memo(m, INT_MAX);
    memo[0] = triangle[0][0];

    for (int r = 1; r < n; r++)
    {
        vector<int> temp = memo;

        for (int c = 0; c <= r; c++)
        {
            int top = memo[c];
            int topLeft = INT_MAX;

            if (c != 0)
            {
                topLeft = memo[c - 1];
            }

            int curr = min(top, topLeft) + triangle[r][c];

            temp[c] = curr;
        }
        memo = temp;
    }

    int minPath = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        minPath = min(minPath, memo[i]);
    }

    return minPath;
}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}