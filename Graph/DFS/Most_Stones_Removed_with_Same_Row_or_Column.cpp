/*

947. Most Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the
largest possible number of stones that can be removed.

*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    unordered_map<int, unordered_set<int>> rows;
    unordered_map<int, unordered_set<int>> cols;
    unordered_set<int> vis;
    int components = 0;

    void dfs(int stone, vector<vector<int>> &stones)
    {
        vis.insert(stone);

        int r = stones[stone][0];
        int c = stones[stone][1];

        for (int neighbour : rows[r])
        {
            if (vis.count(neighbour))
                continue;

            dfs(neighbour, stones);
        }

        for (int neighbour : cols[c])
        {
            if (vis.count(neighbour))
                continue;

            dfs(neighbour, stones);
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();

        for (int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];

            rows[r].insert(i);
            cols[c].insert(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (vis.count(i))
                continue;

            components++;
            dfs(i, stones);
        }

        return n - components;
    }
};

int main()
{

    cout << endl;
    return 0;
}