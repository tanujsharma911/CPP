#include <iostream>

using namespace std;

int helper(int idx, int prevSelect, vector<vector<int>> &arr, vector<int> &memo)
{
    if (idx < 0)
    {
        return 0;
    }

    int maxS = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i == prevSelect)
            continue;

        maxS = max(helper(idx - 1, i, arr, memo) + arr[idx][i], maxS);
    }

    return maxS;
}
int maximumPoints(vector<vector<int>> &arr)
{
    vector<int> memo(arr.size(), -1);

    return helper(arr.size() - 1, -1, arr, memo);
}

int main()
{
    vector<vector<int>> arr = { { 1, 2, 5 }, { 3, 1, 1 }, { 3, 3, 3 }};

    cout << maximumPoints(arr) << endl;

    return 0;
}

/*
Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]

Output: 11

Explanation: Geek will learn a new move and earn 5 point then on second day he will do 
running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum 
merit point will be 11.Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]

*/