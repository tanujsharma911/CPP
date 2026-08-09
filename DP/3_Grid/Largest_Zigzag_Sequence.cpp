/*

Largest Zigzag Sequence

Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends
at the bottom. Two consecutive elements of sequence cannot belong to the same column.

Return the maximum sum of such a zigzag sequence.

Input: mat[][] = [1 5 3], [7 2 4], [6 8 9]
Output: 21

One optimal zigzag sequence is: 5 -> 7 -> 9

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int helper(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &memo)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        if (c < 0)
            return INT_MIN;
        if (c >= cols)
            return INT_MIN;
        if (r == rows - 1)
            return mat[r][c];

        if (memo[r][c] != -1)
            return memo[r][c];

        int cost = INT_MIN;

        for (int k = 0; k < cols; k++)
        {
            if (k == c)
                continue;

            cost = max(cost, mat[r][c] + helper(r + 1, k, mat, memo));
        }

        return memo[r][c] = cost;
    }
    int zigzagSequence(vector<vector<int>> &mat)
    {
        int n = mat.size();

        int cost = INT_MIN;

        vector<vector<int>> memo(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            cost = max(cost, helper(0, i, mat, memo));
        }

        return cost;
    }
};

int main()
{

    cout << endl;
    return 0;
}