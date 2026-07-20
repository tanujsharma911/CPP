/*

Prim's Algorithm

Minimum Spanning Tree


*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int spanningTree(int V, vector<vector<int>> &edges)
   {
      vector<vector<pair<int, int>>> adj(V);

      for (auto edge : edges)
      {
         int from = edge[0];
         int to = edge[1];
         int weight = edge[2];

         adj[from].push_back({to, weight});
         adj[to].push_back({from, weight});
      }

      int mst_sum = 0;

      vector<int> vis(V, 0);
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; // {weight, {node, parent}}

      q.push({0, {0, -1}});

      while (!q.empty())
      {
         int weight = q.top().first;
         int node = q.top().second.first;
         int parent = q.top().second.second;
         q.pop();

         if (vis[node] == 1)
            continue;

         vis[node] = 1;

         // cout << parent << " -> " << node << " : " << weight << endl;

         if (parent != -1)
         {
            mst_sum += weight;
         }

         for (auto neighbour : adj[node])
         {
            int to = neighbour.first;
            int cost = neighbour.second;

            q.push({cost, {to, node}});
         }
      }

      return mst_sum;
   }
};

int main()
{

   cout << endl;
   return 0;
}