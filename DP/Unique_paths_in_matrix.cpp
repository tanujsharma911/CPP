/*
There is a robot on an m x n grid. The robot is initially located at the top-left
corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to
reach the bottom-right corner.
*/

#include <iostream>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<int> topMemo(n, 0);
    int leftMemo = 0;

    topMemo[0] = 1;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {

            int top = topMemo[c];
            int left = leftMemo;

            topMemo[c] = top + left;
            leftMemo = top + left;
        }

        leftMemo = 0;
    }

    return topMemo[n - 1];
}

int main()
{
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl;
    return 0;
}

/*
Input: m = 3, n = 7
Output: 28
*/