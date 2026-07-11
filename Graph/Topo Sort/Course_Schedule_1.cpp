/*

207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you
must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
   {
      vector<vector<int>> adj(numCourses);
      vector<int> in_degree(numCourses, 0);

      for (int i = 0; i < prerequisites.size(); i++)
      {
         int course = prerequisites[i][0];
         int prerequisite = prerequisites[i][1];

         in_degree[prerequisite]++;

         adj[course].push_back(prerequisite);
      }

      queue<int> q;

      for (int i = 0; i < numCourses; i++)
      {
         if (in_degree[i] == 0)
         {
            q.push(i);
         }
      }

      int processed = 0;

      while (!q.empty())
      {
         int course = q.front();
         q.pop();

         processed++;

         for (auto neighbour : adj[course])
         {
            in_degree[neighbour]--;

            if (in_degree[neighbour] == 0)
            {
               q.push(neighbour);
            }
         }
      }

      return processed == numCourses;
   }
};

int main()
{

   cout << endl;
   return 0;
}