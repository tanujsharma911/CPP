/*

787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array
flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight
from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from
src to dst with at most k stops. If there is no such route, return -1.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
   {
      vector<vector<pair<int, int>>> adj(n);

      for (auto flight : flights)
      {
         int from = flight[0];
         int to = flight[1];
         int cost = flight[2];

         adj[from].push_back({to, cost});
      }

      vector<int> dist(n, INT_MAX);
      dist[src] = 0;

      queue<pair<int, pair<int, int>>> q;
      q.push({0, {src, 0}});

      while (!q.empty())
      {
         int steps = q.front().first;
         int node = q.front().second.first;
         int cost = q.front().second.second;
         q.pop();

         if (steps > k)
            continue;

         for (auto neighbour : adj[node])
         {
            if (cost + neighbour.second > dist[neighbour.first])
               continue;

            q.push({steps + 1, {neighbour.first, cost + neighbour.second}});
            dist[neighbour.first] = cost + neighbour.second;
         }
      }

      if (dist[dst] == INT_MAX)
         return -1;

      return dist[dst];
   }
};

int main()
{

   cout << endl;
   return 0;
}