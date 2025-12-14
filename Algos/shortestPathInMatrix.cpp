// shortest path in matrix

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// only move in 4D and on 1
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int dis = curr.first;
        int r = curr.second.first;
        int c = curr.second.second;

        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dist[newr][newc] > dis + 1)
            {
                if (newr == destination.first && newc == destination.second)
                {
                    return dis + 1;
                }
                dist[newr][newc] = dis + 1;
                q.push({dis + 1, {newr, newc}});
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 0, 1, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}};

    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    cout << shortestPath(grid, source, destination) << endl;

    return 0;
}