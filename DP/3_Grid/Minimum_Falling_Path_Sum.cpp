/*
931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next
row that is either directly below or diagonally left/right. Specifically, the next element
from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Input: matrix = [[2,1,3],
                [6,5,4],
                [7,8,9]]
Output: 13 = 1 + 5 + 7, 1 + 4 + 8
Explanation: There are two falling paths with a minimum sum as shown.

*/

#include <iostream>

using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int minSum = INT_MAX;

    vector<int> memo(m, -1);

    for (int k = 0; k < m; k++)
    {
        memo[k] = matrix[n - 1][k];
    }

    for (int r = n - 2; r >= 0; r--)
    {
        vector<int> temp = memo;

        for (int c = 0; c < m; c++)
        {
            int left = INT_MAX;
            if (c - 1 >= 0)
                left = memo[c - 1];

            int below = memo[c];

            int right = INT_MAX;
            if (c + 1 < m)
                right = memo[c + 1];

            int curr = min(left, below);
            curr = min(curr, right);

            curr += matrix[r][c];

            temp[c] = curr;
        }

        memo = temp;
    }

    for (int i = 0; i < m; i++)
    {
        minSum = min(minSum, memo[i]);
    }

    return minSum;
}

int main()
{
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};

    cout << minFallingPathSum(matrix) << endl;

    return 0;
}