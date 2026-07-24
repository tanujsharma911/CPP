/*

1631. Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell,
(0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

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
   int minimumEffortPath(vector<vector<int>> &heights)
   {
      int rows = heights.size();
      int cols = heights[0].size();

      vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));

      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
      q.push({0, {0, 0}});
      dis[0][0] = 0;

      while (!q.empty())
      {
         int diff = q.top().first;
         int r = q.top().second.first;
         int c = q.top().second.second;
         q.pop();

         if (r == rows - 1 && c == cols - 1)
         {
            return diff;
         }

         for (int i = 0; i < 4; i++)
         {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols)
               continue;

            int distance = abs(heights[new_r][new_c] - heights[r][c]);

            if (distance >= dis[new_r][new_c])
               continue;

            dis[new_r][new_c] = distance;
            q.push({max(diff, distance), {new_r, new_c}});
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