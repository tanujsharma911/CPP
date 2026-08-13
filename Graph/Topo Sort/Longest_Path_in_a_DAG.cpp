/*

Longest Path in a Directed Acyclic Graph

Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1,
represented by edges[][], where edges[i] = [u, v, w] denotes a directed edge from u to v
with weight w, and a source vertex src.

Return the distance array, where the value at index i represents the longest distance from s to vertex i.
If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will
automatically display INT_MIN as INF.

Examples :

Input: V = 4, src = 0, edges[][] = [[0, 1, 1], [0, 2, 1], [1, 2, 5], [3, 1, 2], [3, 2, -1]]
Output: [0, 1, 6, INF]
Explanation: The longest distance of vertex 1 from 0 is 1, vertex 2 is 6 and vertex 3 is unreachable so INF.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    void topoSort(int u, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (auto &[v, w] : adj[u])
        {
            if (!visited[v])
            {
                topoSort(v, adj, visited, st);
            }
        }

        st.push(u);
    }
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // topological sort (DFS-based)
        vector<bool> visited(V, false);

        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topoSort(i, adj, visited, st);
            }
        }

        // 2, 3, 4, 1, 0

        // longest path via DP over topo order
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MIN)
            {
                for (auto &[v, w] : adj[u])
                {
                    if (dist[u] + w > dist[v])
                    {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        return dist;
    }
};

int main()
{

    cout << endl;
    return 0;
}