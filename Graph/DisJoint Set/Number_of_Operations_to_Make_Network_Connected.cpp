/*

1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections
forming a network where connections[i] = [ai, bi] represents a connection between computers
ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables
between two directly connected computers, and place them between any pair of disconnected
computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers
connected. If it is not possible, return -1.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class DisJoint
{
public:
  vector<int> parent;
  vector<int> size;

  DisJoint(int n)
  {
    parent.resize(n);
    size.resize(n, 1);

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int findParent(int node)
  {
    if (parent[node] == node)
      return node;

    return parent[node] = findParent(parent[node]);
  }

  void unionBySize(int a, int b)
  {
    int parent_a = findParent(a);
    int parent_b = findParent(b);

    if (parent_a == parent_b)
      return;

    if (size[parent_a] > size[parent_b])
    {
      size[parent_a] += size[parent_b];
      parent[parent_b] = parent_a;
    }
    else
    {
      size[parent_b] += size[parent_a];
      parent[parent_a] = parent_b;
    }
  }

  bool fromSameComponent(int a, int b)
  {
    int parent_a = findParent(a);
    int parent_b = findParent(b);

    return (parent_a == parent_b);
  }
};
class Solution
{
public:
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    DisJoint ds(n);
    int extraEdges = 0;
    int components = n;

    for (auto edge : connections)
    {
      int a = edge[0];
      int b = edge[1];

      if (ds.fromSameComponent(a, b))
      {
        extraEdges++;
      }
      else
      {
        ds.unionBySize(a, b);
        components--;
      }
    }

    if (extraEdges >= components - 1)
    {
      return min(extraEdges, components - 1);
    }

    return -1;
  }
};

/*

Un-directed graph

*/

int main()
{

  cout << endl;
  return 0;
}