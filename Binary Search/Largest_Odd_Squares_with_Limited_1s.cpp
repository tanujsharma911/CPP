/*

Largest Odd Squares with Limited 1s

Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries
queries[][]. Each query contains coordinates [i, j] of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell
(i, j) such that the square contains at most k ones.
 A square centered at (i, j) expands outward symmetrically in all four directions by the
 same number of cells, so its side length is always odd.

Input: mat[][] = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]], queries[][] = [[1, 2]], k = 9
Output: [3]
Explanation: The largest odd-sized square centered at (1, 2) is the 3 × 3 square spanning rows 0 to 2 and columns 1 to 3.
It contains 6 ones, which is at most k = 9. Hence, the answer is 3.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> prefix;
    int rows, cols;

    void calPrefix(vector<vector<int>> &mat)
    {

        prefix.resize(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + mat[i - 1][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int onceInSubgrid(int i, int j, int r)
    {
        return prefix[i + r + 1][j + r + 1] - prefix[i - r][j + r + 1] - prefix[i + r + 1][j - r] + prefix[i - r][j - r];
    }

    int largestOddSquare(int i, int j, int k)
    {
        int maxRadius = min({i, rows - i - 1, j, cols - j - 1});

        if (onceInSubgrid(i, j, 0) > k)
            return -1;

        int lo = 0, hi = maxRadius;
        int largest_radius = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int once = onceInSubgrid(i, j, mid);

            if (once <= k)
            {
                largest_radius = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return largest_radius * 2 + 1;
    }

    vector<int> largestSquare(vector<vector<int>> &mat, vector<vector<int>> &queries, int k)
    {
        rows = mat.size();
        cols = mat[0].size();

        calPrefix(mat);

        vector<int> ans;

        for (auto query : queries)
        {
            int i = query[0];
            int j = query[1];

            ans.push_back(largestOddSquare(i, j, k));
        }

        return ans;
    }
};

/*

[1, 0, 1, 0, 0],
[1, 0, 1, 1, 1],
[1, 1, 1, 1, 1],
[1, 0, 0, 1, 0]




*/

int main()
{

    cout << endl;
    return 0;
}