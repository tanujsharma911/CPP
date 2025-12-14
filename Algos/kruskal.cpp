#include <iostream>

using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findHighestParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findHighestParent(parent[node]); // finding highest parent with path compression
    }
    void unionBySize(int a, int b)
    {
        int h_a = findHighestParent(a);
        int h_b = findHighestParent(b);

        if (h_a == h_b)
            return;
        else if (size[h_a] < size[h_b])
        {
            parent[h_a] = h_b;
            size[h_b] += size[h_a];
        }
        else
        {
            parent[h_b] = h_a;
            size[h_a] += size[h_b];
        }
    }

    bool fromSameCompoenet(int a, int b)
    {
        if (findHighestParent(a) == findHighestParent(b))
            return true;

        else
            return false;
    }
};

int main()
{
    // vector<vector<int>> connections = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    // int v = 3;
    vector<vector<int>> connections = {
        {0, 1, 10},
        {1, 2, 6},
        {2, 3, 5},
        {3, 0, 15},
        {0, 2, 4}};
    int v = 4;

    // first convert them into {wt, {node, neighbour}}
    vector<pair<int, pair<int, int>>> edges;
    for (auto edge : connections)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        edges.push_back({wt, {u, v}});
    }

    // sort them
    sort(edges.begin(), edges.end());

    DisjointSet ds(v);
    int mst_value = 0;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.fromSameCompoenet(u, v))
        {
            // no need add
        }
        else
        {
            // make connection b/w them
            mst_value += wt;
            ds.unionBySize(u, v);
        }
    }

    cout << "MST: " << mst_value << endl;

    return 0;
}