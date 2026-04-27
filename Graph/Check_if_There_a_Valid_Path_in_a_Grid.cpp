
/*
1391. Check if There is a Valid Path in a Grid

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


valid
{
    "1": [null, [3, 5, 1], null, [1, 4, 6]],
    "2": [[2, 3, 4], null, [2, 5, 6], null],
    "3": [null, null, [5, 6, 2], [4, 6, 1]],
    "4": [null, [1, 3, 6], [5, 6, 2], null],
    "5": [[2, 3, 4], null, null, [1, 4, 6]],
    "6": [[2, 3, 4], [5, 3, 1], null, null]
}

*/

#include <iostream>
#include <unordered_set>

using namespace std;

vector<vector<unordered_set<int>>> data = {
    {},                             // Index 0 (Unused, so indices match your 1-6 keys)
    {{}, {3, 5, 1}, {}, {1, 4, 6}}, // Index 1
    {{2, 3, 4}, {}, {2, 5, 6}, {}}, // Index 2
    {{}, {}, {5, 6, 2}, {4, 6, 1}}, // Index 3
    {{}, {1, 3, 6}, {5, 6, 2}, {}}, // Index 4
    {{2, 3, 4}, {}, {}, {1, 4, 6}}, // Index 5
    {{2, 3, 4}, {5, 3, 1}, {}, {}}  // Index 6
};
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

bool validCell(int r, int c, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if (r >= n || r < 0)
        return false;
    if (c >= m || c < 0)
        return false;
    return true;
}

bool connected(int r1, int c1, int dir, vector<vector<int>> &grid)
{
    int curr_street = grid[r1][c1];

    int r2 = r1 + dr[dir];
    int c2 = c1 + dc[dir];

    if (!validCell(r2, c2, grid))
        return false;

    int next_street = grid[r2][c2];

    unordered_set<int> validStreets = data[curr_street][dir];

    if (validStreets.count(next_street))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool hasValidPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push({0, 0});
    vis[0][0] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == n - 1 && c == m - 1)
            return true;

        for (int dir = 0; dir < 4; dir++)
        {
            int new_r = r + dr[dir];
            int new_c = c + dc[dir];

            if (validCell(new_r, new_c, grid) && vis[new_r][new_c] == 0 && connected(r, c, dir, grid))
            {

                q.push({new_r, new_c});
                vis[new_r][new_c] = 1;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};

    cout << hasValidPath(grid);

    cout << endl;
    return 0;
}