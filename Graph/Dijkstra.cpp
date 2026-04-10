#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_shortest_path(int start, int end, vector<vector<vector<int>>> &adj, vector<int> &parent, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    parent[start] = 0; // Parent of start will be itself

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        for (auto edge : adj[node])
        {
            int neighbour = edge[0];
            int weight = edge[1];

            int newDis = dis + weight;

            if (newDis < dist[neighbour])
            {
                dist[neighbour] = newDis;
                parent[neighbour] = node;
                pq.push({newDis, neighbour});
            }
        }
    }

    if (dist[end] == INT_MAX)
    {
        cout << "Unreachable" << endl;
    }

    int node = end;
    while (dist[node])
    {
        cout << node << " <- ";
        node = parent[node];
    }
    cout << node;
}

int main()
{
    // vector<vector<vector<int>>> adj = {
    //     {{1, 2}, {2, 4}},          // node 0 → (1,2), (2,4)
    //     {{0, 2}, {2, 5}, {3, 10}}, // node 1 → (0,2), (2,5), (3,10)
    //     {{0, 4}, {1, 5}, {3, 3}},  // node 2 → (0,4), (1,5), (3,3)
    //     {{1, 10}, {2, 3}},         // node 3 → (1,10), (2,3)
    //     {}                         // node 4
    // };

    vector<vector<vector<int>>> adj = {
        /* 0 */ {{1, 4}, {2, 1}, {3, 7}},
        /* 1 */ {{0, 4}, {4, 3}, {5, 2}},
        /* 2 */ {{0, 1}, {5, 8}, {6, 5}},
        /* 3 */ {{0, 7}, {6, 6}, {7, 4}},
        /* 4 */ {{1, 3}, {8, 2}},
        /* 5 */ {{1, 2}, {2, 8}, {8, 7}, {9, 3}},
        /* 6 */ {{2, 5}, {3, 6}, {9, 4}},
        /* 7 */ {{3, 4}, {9, 6}},
        /* 8 */ {{4, 2}, {5, 7}, {9, 1}},
        /* 9 */ {{5, 3}, {6, 4}, {7, 6}, {8, 1}}};

    int V = adj.size();

    vector<int> parent(V, 0);
    vector<int> dist(V, INT_MAX);

    print_shortest_path(0, 8, adj, parent, dist);

    // for (auto dis : dist)
    // {
    //     cout << dis << " ";
    // }
    cout << endl;

    return 0;
}