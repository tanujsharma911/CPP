#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int V, vector<int> adj[]) {
    vector<int> in_degree(V, 0);
    vector<int> result;
    queue<int> q;

    // 1. Calculate in-degree of every vertex
    for (int i = 0; i < V; i++) {
        for (auto neighbor : adj[i]) {
            in_degree[neighbor]++;
        }
    }

    // 2. Push all vertices with in-degree 0 to queue
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // 3. Process the queue
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        // Reduce in-degree of neighbors
        for (auto neighbor : adj[curr]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Output the result
    if (result.size() != V) {
        cout << "Cycle detected! Topological sort not possible.";
    } else {
        for (int node : result) cout << node << " ";
    }
}

int main() {
    int V = 6;
    vector<int> adj[6];

    // Defining edges (Directed Acyclic Graph)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort: ";
    topologicalSort(V, adj);

    cout << endl;

    return 0;
}