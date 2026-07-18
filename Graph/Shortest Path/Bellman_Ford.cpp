/*

Bellman–Ford Algorithm

Shortest distances from the source to all other vertices

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
   vector<int> dist(V, 1e8);
   dist[src] = 0;

   for (int i = 0; i < V; i++)
   {

      for (vector<int> edge : edges)
      {
         int from = edge[0];
         int to = edge[1];
         int weight = edge[2];

         if (dist[from] != 1e8 && dist[from] + weight < dist[to])
         {
            // a negative cycle
            if (i == V - 1)
               return {-1};

            dist[to] = dist[from] + weight;
         }
      }
   }

   return dist;
}

int main()
{
   int V = 5;

   // Edge list: {from, to, weight}
   vector<vector<int>> edges = {
       {1, 3, 2},
       {4, 3, -1},
       {2, 4, 1},
       {1, 2, 1},
       {0, 1, 5}};

   int src = 0;

   vector<int> ans = bellmanFord(V, edges, src);

   // Output the shortest distances from src to all vertices
   for (int dist : ans)
      cout << dist << " ";

   cout << endl;
   return 0;
}