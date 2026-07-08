/*

Towers Reaching Both Stations

Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal
strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers
in the four directions (North, South, East, and West) only if the neighbouring
tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers (x, y) from which a signal can eventually
reach both Station P and Station Q. Any tower located on a boundary covered by
a station can transmit directly to that station.

*/

#include <iostream>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
   vector<int> dr = {-1, 0, 1, 0};
   vector<int> dc = {0, 1, 0, -1};

   void dfs(int r, int c, vector<vector<int>> &signal, set<pair<int, int>> &towers)
   {
      int rows = signal.size();
      int cols = signal[0].size();

      towers.insert({r, c});

      for (int i = 0; i < 4; i++)
      {
         int new_r = r + dr[i];
         int new_c = c + dc[i];

         if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
         {
            if (signal[new_r][new_c] < signal[r][c])
               continue;
            if (towers.count({new_r, new_c}))
               continue;

            dfs(new_r, new_c, signal, towers);
         }
      }
   }

   int countCoordinates(vector<vector<int>> &signal)
   {
      int rows = signal.size();
      int cols = signal[0].size();

      set<pair<int, int>> pReachablesTowers;
      set<pair<int, int>> qReachablesTowers;

      for (int r = 0; r < rows; r++)
      {
         if (!pReachablesTowers.count({r, 0}))
            dfs(r, 0, signal, pReachablesTowers);

         if (!qReachablesTowers.count({r, cols - 1}))
            dfs(r, cols - 1, signal, qReachablesTowers);
      }

      for (int c = 0; c < cols; c++)
      {
         if (!pReachablesTowers.count({0, c}))
            dfs(0, c, signal, pReachablesTowers);

         if (!qReachablesTowers.count({rows - 1, c}))
            dfs(rows - 1, c, signal, qReachablesTowers);
      }

      int reachablesToBothStations = 0;

      for (int r = 0; r < rows; r++)
      {
         for (int c = 0; c < cols; c++)
         {
            if (pReachablesTowers.count({r, c}) && qReachablesTowers.count({r, c}))
            {
               reachablesToBothStations++;
            }
         }
      }

      return reachablesToBothStations;
   }
};

int main()
{

   cout << endl;
   return 0;
}