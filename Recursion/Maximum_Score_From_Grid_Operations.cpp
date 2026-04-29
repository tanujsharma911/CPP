// 3225. Maximum Score From Grid Operations

#include <iostream>

using namespace std;

/*
Brute force
Runtime Error
616 / 794 testcases passed

T: O(n² * n^n)
*/
class Solution
{
public:
    long long maxScore = 0;
    int n;
    vector<vector<int>> grid;

    long long maximumScore(vector<vector<int>> &g)
    {
        n = g.size();
        this->grid = g;

        vector<int> choices(n, -1);

        solve(0, choices);

        return maxScore;
    }
    void solve(int col, vector<int> &choices)
    {
        if (col == n)
        {
            maxScore = max(maxScore, calculateScore(choices));
            return;
        }

        // Try all n+1 possibilities for the current column's operation
        // i = -1 means no operation (0 black cells)
        // i = 0..n-1 means operation on (i, col)
        for (int i = -1; i < n; i++)
        {
            choices[col] = i;
            solve(col + 1, choices);
        }
    }
    long long calculateScore(vector<int> &choices)
    {
        int score = 0;

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (r > choices[c])
                {
                    bool hasBlackNeighbour = false;

                    // check left for black
                    if (c > 0 && r <= choices[c - 1])
                    {
                        hasBlackNeighbour = true;
                    }

                    // check right for black
                    else if (c < n - 1 && r <= choices[c + 1])
                    {
                        hasBlackNeighbour = true;
                    }

                    if (hasBlackNeighbour)
                    {
                        score += grid[r][c];
                    }
                }
            }
        }

        return score;
    }
};

int main()
{

    cout << endl;
    return 0;
}