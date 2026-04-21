// 695. Max Area of Island

#include <iostream>

using namespace std;

int getAreaOfIsland(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    queue<pair<int, int>> q;

    q.push({r, c});

    int areaOfIsland = 0;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        areaOfIsland++;

        for (int i = 0; i < 4; i++)
        {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && visited[new_r][new_c] == 0 && grid[new_r][new_c] == 1)
            {
                visited[new_r][new_c] = 1;
                q.push({new_r, new_c});
            }
        }
    }

    return areaOfIsland;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    int maxArea = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (visited[r][c] == 1 || grid[r][c] == 0)
                continue;

            visited[r][c] = 1;
            int areaOfCurrIsland = getAreaOfIsland(r, c, grid, visited);

            maxArea = max(maxArea, areaOfCurrIsland);
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    cout << maxAreaOfIsland(grid);

    cout << endl;
    return 0;
}