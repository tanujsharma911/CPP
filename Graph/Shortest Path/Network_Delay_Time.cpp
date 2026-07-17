/*

743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times,
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node,
 vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n
nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int networkDelayTime(vector<vector<int>> &times, int n, int k)
   {
      vector<vector<pair<int, int>>> adj(n + 1);

      for (auto time : times)
      {
         int from = time[0];
         int to = time[1];
         int cost = time[2];

         adj[from].push_back({to, cost});
      }

      vector<int> dist(n + 1, INT_MAX);
      dist[k] = 0;

      queue<int> q;
      q.push(k);

      while (!q.empty())
      {
         int node = q.front();
         q.pop();

         for (auto neighbour : adj[node])
         {
            if (dist[node] + neighbour.second < dist[neighbour.first])
            {
               q.push(neighbour.first);
               dist[neighbour.first] = dist[node] + neighbour.second;
            }
         }
      }

      int longestDelay = INT_MIN;

      for (int i = 1; i <= n; i++)
      {
         if (dist[i] == INT_MAX)
            return -1;

         longestDelay = max(longestDelay, dist[i]);
      }

      return longestDelay;
   }
};

int main()
{

   cout << endl;
   return 0;
}