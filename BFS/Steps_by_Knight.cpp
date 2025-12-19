#include <iostream>

using namespace std;

int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
{
    if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1])
    {
        return 0;
    }

    vector<int> dr = {-2, -2, -1, 1, 2, 2, 1, -1};
    vector<int> dc = {-1, 1, 2, 2, 1, -1, -2, -2};

    vector<vector<int>> vis(n, vector<int>(n, 0));

    int r = knightPos[0] - 1;
    int c = knightPos[1] - 1;
    vis[r][c] = 1;

    queue<vector<int>> q;
    q.push({r, c, 0});

    while (!q.empty())
    {
        auto cell = q.front();

        int r = cell[0];
        int c = cell[1];
        int steps = cell[2];

        q.pop();

        if (r == targetPos[0] - 1 && c == targetPos[1] - 1)
        {
            return steps;
        }

        for (int i = 0; i < 8; i++)
        {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && vis[new_r][new_c] == 0)
            {
                vis[new_r][new_c] = 1;
                q.push({new_r, new_c, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 6;
    vector<int> knightPos = {4, 5}, targetPos = {1, 1};

    cout << minStepToReachTarget(knightPos, targetPos, n) << endl;

    return 0;
}

/*
Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
*/