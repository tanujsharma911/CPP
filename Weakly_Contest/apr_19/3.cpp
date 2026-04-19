// Accepted

#include <iostream>

using namespace std;

struct CompareVector
{
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        if (a[0] != b[0])
        {
            return a[0] > b[0];
        }

        return a[1] < b[1];
    }
};

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

vector<vector<int>> colorGrid(int rows, int cols, vector<vector<int>> &sources)
{
    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    for (auto source : sources)
    {
        grid[source[0]][source[1]] = source[2];
    }

    priority_queue<vector<int>, vector<vector<int>>, CompareVector> q;

    int t = 0;

    for (auto source : sources)
    {
        q.push({t, source[2], source[0], source[1]}); // {time, color, row, col}
    }

    t++;

    while (!q.empty())
    {
        int curr_time = q.top()[0];
        int curr_color = q.top()[1];
        int curr_row = q.top()[2];
        int curr_col = q.top()[3];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int n_row = curr_row + dr[i];
            int n_col = curr_col + dc[i];

            if (n_row < rows && n_row >= 0 && n_col < cols && n_col >= 0 && grid[n_row][n_col] == 0)
            {
                grid[n_row][n_col] = curr_color;
                q.push({curr_time + 1, curr_color, n_row, n_col});
            }
        }
    }

    return grid;
}

int main()
{
    int n = 2, m = 2;

    vector<vector<int>> sorces = {{1, 1, 5}};
    vector<vector<int>> ans = colorGrid(n, m, sorces);

    for (auto row : ans)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}