

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
    int findHParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findHParent(parent[node]); // finding highest parent with path compression
    }
    void unionBySize(int a, int b)
    {
        int h_a = findHParent(a);
        int h_b = findHParent(b);

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
        if (findHParent(a) == findHParent(b))
            return true;

        else
            return false;
    }
};

int main()
{

    return 0;
}