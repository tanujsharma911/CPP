#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& g) {
    int n = g[0].size() * g.size();
    int left = -1;
    int top = -1;
    int right = g[0].size();
    int bottom = g.size();

    int curr_x = 0, curr_y = 0;

    vector<int> ans;

    while (ans.size() < n)
    {
        while (curr_x < right) // right
        {
            // cout << g[x][i] << " ";
            ans.push_back(g[curr_y][curr_x]);
            curr_x++;
        }
        top = curr_y;

        curr_x--;
        curr_y++;

        if(ans.size() >= n) break;

        while (curr_y < bottom) // down
        {
            // cout << g[i][m - 1 - x] << " ";
            ans.push_back(g[curr_y][curr_x]);
            curr_y++;
        }
        right = curr_x;

        curr_y--;
        curr_x--;

        if(ans.size() >= n) break;

        while (curr_x > left) // left
        {
            // cout << g[n - 1 - x][i] << " ";
            ans.push_back(g[curr_y][curr_x]);
            curr_x--;
        }
        bottom = curr_y;

        curr_x++;
        curr_y--;

        if(ans.size() >= n) break;

        while (curr_y > top) // up
        {
            // cout << g[i][x] << " ";
            ans.push_back(g[curr_y][curr_x]);
            curr_y--;
        }
        left = curr_x;

        curr_y++;
        curr_x++;
    }

    return ans;
}

int main()
{


    return 0;
}
