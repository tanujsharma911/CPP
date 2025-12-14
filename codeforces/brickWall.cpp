/*
Problem Description
A plumber needs to install pipelines on a brick wall. To do this, some bricks must be broken to fit the pipes.

There are two types of bricks in the wall:

Red Bricks (R): Hard to break.
Green Bricks (G): Easy to break.
The plumber will only break Green Bricks to make the job easier. The wall is represented as a square grid, with each brick type and its length specified (e.g., "3R" means a Red Brick of length equal to three unit Bricks). The wall also includes a Source (S) where the pipe starts and a Destination (D) where it ends.

Pipes can be laid either vertically or horizontally, moving from the current brick to any adjacent Green Brick (up, down, left, or right). The goal is to find the minimum number of Green Bricks that must be broken to connect the source to the destination. Red Bricks cannot be used.

Assume the layout of the brick wall is shown below.

The input notation to represent the above brick wall is shown below:

3R1D
1R1R1R1G
2G1G1G
2S2R

Constraints
3<=N<=25

Input
The first line contains N, the size of the wall (N x N).
The next N lines describe the wall layout using the notation above.

Output
Print a single integer: the least number of Green Bricks that need to be broken.


Input:
3R1D 1R1R1R1G 2G1G1G 2S2R

3G1R1G 1G1R1G2R 1S1R1G1R1D 2R1G1R1G 5G
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

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

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dist[newr][newc] > dis + 1)
            {
                if (newr == destination.first && newc == destination.second)
                {
                    return dis;
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
    int n;
    cin >> n;

    vector<string> input;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> sources;
    pair<int, int> destination;

    for (int i = 0; i < n; i++) // taking input
    {
        string temp = "";
        cin >> temp;
        input.push_back(temp);
    }

    for (int i = 0; i < n; i++) // converting into grid
    {
        int c = 0;
        for (int j = 0; j < input[i].length(); j = j + 2)
        {
            cout << input[i][j] << input[i][j + 1] << " ";

            for (int k = 0; k < input[i][j] - '0'; k++)
            {
                if (input[i][j + 1] == 'R')
                    grid[i][c] = 1;

                else if (input[i][j + 1] == 'S')
                {
                    sources.push_back({i, c});
                }
                else if (input[i][j + 1] == 'D')
                {
                    destination = {i, c};
                }

                c++;
            }
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "S: ";
    int ans = INT_MAX;
    for (int i = 0; i < sources.size(); i++)
    {
        cout << sources[i].first << ", " << sources[i].second << endl;
        ans = min(ans, shortestPath(grid, sources[i], destination));
    }
    // cout << destination.first << ", " << destination.second << endl;
    cout << "\nAns: " << ans << endl;

    return 0;
}