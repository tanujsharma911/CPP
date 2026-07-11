
/*

Longest Possible Route in a Matrix with Hurdles

Given a binary matrix mat[][] of size n × m containing values 0 and 1, and
four integers xs, ys, xd, and yd representing the source cell (xs, ys) and
destination cell (xd, yd), find the length of the longest possible path from
the source cell to the destination cell. From any cell, you can move to its
adjacent cells in the up, down, left, and right directions.

1 represents a traversable cell.
0 represents a blocked cell that cannot be visited.
A cell can be visited at most once in a path.
If the destination cannot be reached from the source, return -1.

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

   int longest_path = -1;

   void dfs(int r, int c, int steps, vector<vector<int>> &mat, vector<vector<bool>> &vis, int xd, int yd)
   {
      int rows = mat.size();
      int cols = mat[0].size();

      if (r == xd && c == yd)
      {
         longest_path = max(steps, longest_path);
         return;
      }

      for (int i = 0; i < 4; i++)
      {
         int new_r = r + dr[i];
         int new_c = c + dc[i];

         if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && !vis[new_r][new_c])
         {
            if (mat[new_r][new_c] == 0)
               continue;

            vis[new_r][new_c] = true;
            dfs(new_r, new_c, steps + 1, mat, vis, xd, yd);
            vis[new_r][new_c] = false;
         }
      }
   }
   int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
   {
      int rows = mat.size();
      int cols = mat[0].size();

      vector<vector<bool>> vis(rows, vector<bool>(cols, false));

      vis[xs][ys] = true;
      dfs(xs, ys, 0, mat, vis, xd, yd);

      return longest_path;
   }
};

int main()
{

   cout << endl;
   return 0;
}