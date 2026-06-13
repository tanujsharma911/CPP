/*

547. Number of Provinces

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class DisJointSet
{
public:
    vector<int> parent, size;

    DisJointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int a, int b)
    {
        int a_parent = findParent(a);
        int b_parent = findParent(b);

        if (a_parent == b_parent)
            return;
        else if (size[a_parent] >= size[b_parent])
        {
            parent[b_parent] = a_parent;
            size[a_parent] += size[b_parent];
        }
        else
        {
            parent[a_parent] = b_parent;
            size[b_parent] += size[a_parent];
        }
    }
    bool inSameComponent(int a, int b)
    {
        return findParent(a) == findParent(b);
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        DisJointSet ds(n);

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (r == c)
                    continue;

                if (isConnected[r][c] == 1)
                {
                    ds.unionBySize(r, c);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                provinces++;
            }
        }

        return provinces;
    }
};

/*

[1,1,0],
[1,1,0],
[0,0,1]

*/

int main()
{

    cout << endl;
    return 0;
}