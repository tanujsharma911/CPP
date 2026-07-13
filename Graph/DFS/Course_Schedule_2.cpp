/*

Course Schedule II

You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][]
where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.

Find the ordering of courses we should take to complete all the courses.

Note: There may be multiple correct orders, you just need to return any one of them.
If it is impossible to finish all tasks, return an empty array. The Driver code will
print true if you return any correct order of courses else it will print false.

Cycle detection + TopoSort (But using DFS)

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   vector<int> result;
   bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis)
   {
      if (adj[node].size() == 0)
      {
         result.push_back(node);
         return false;
      }

      bool isCycle = false;

      for (int neighbour : adj[node])
      {
         if (!vis[neighbour])
         {
            vis[neighbour] = true;
            isCycle = dfs(neighbour, node, adj, vis);
         }
         else
         {
            return true;
         }
      }

      if (!isCycle)
         result.push_back(node);

      return isCycle;
   }
   vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
   {
      vector<vector<int>> adj(n);

      for (auto prerequisite : prerequisites)
      {
         int x = prerequisite[0];
         int y = prerequisite[1];

         adj[x].push_back(y);
      }

      vector<bool> vis(n, false);

      for (int i = 0; i < n; i++)
      {
         if (!vis[i])
         {
            vis[i] = true;

            if (dfs(i, -1, adj, vis))
            {
               return {};
            }
         }
      }

      return result;
   }
};

int main()
{

   cout << endl;
   return 0;
}