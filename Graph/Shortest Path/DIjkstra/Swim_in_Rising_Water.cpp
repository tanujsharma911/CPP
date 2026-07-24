/*

778. Swim in Rising Water

You are given an n x n integer matrix grid where each value grid[i][j] represents the
elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t,
meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the
elevation of both squares individually are at most t. You can swim infinite distances in zero
time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you
start at the top left square (0, 0).

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    int swimInWater(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        q.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!q.empty())
        {
            int highestPoint = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();

            if (r == rows - 1 && c == cols - 1)
                return highestPoint;

            for (int i = 0; i < 4; i++)
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];

                if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols)
                    continue;

                int new_highestPoint = max(highestPoint, grid[new_r][new_c]);

                if (new_highestPoint >= dist[new_r][new_c])
                    continue;

                q.push({new_highestPoint, {new_r, new_c}});
                dist[new_r][new_c] = new_highestPoint;
            }
        }

        return -1;
    }
};

int main()
{

    cout << endl;
    return 0;
}