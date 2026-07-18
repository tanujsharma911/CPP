/*

Floyd Warshall Algorithm

Determine the shortest path distance between all pair of nodes in the graph.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

void floydWarshall(vector<vector<int>> &dist)
{
   int V = dist.size();
   int INF = 1e8;

   // for each intermediate vertex
   for (int k = 0; k < V; k++)
   {

      // Pick all vertices as source one by one
      for (int from = 0; from < V; from++)
      {

         // Pick all vertices as destination
         // for the above picked source
         for (int to = 0; to < V; to++)
         {

            // shortest path from "from" to "to"
            if (dist[from][k] != INF && dist[k][to] != INF)
               dist[from][to] = min(dist[from][to],
                                    dist[from][k] + dist[k][to]);
         }
      }
   }
}

int main()
{
   int INF = 1e8;
   vector<vector<int>> dist = {{0, 4, INF, 5, INF},
                               {INF, 0, 1, INF, 6},
                               {2, INF, 0, 3, INF},
                               {INF, INF, 1, 0, 2},
                               {1, INF, INF, 4, 0}};

   floydWarshall(dist);

   for (int i = 0; i < dist.size(); i++)
   {
      for (int j = 0; j < dist.size(); j++)
      {
         cout << dist[i][j] << " ";
      }
      cout << endl;
   }

   cout << endl;
   return 0;
}