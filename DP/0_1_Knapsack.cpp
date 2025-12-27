/*
Given two arrays, val[] and wt[], where each element represents the value and weight 
of an item respectively, and an integer W representing the maximum capacity of the 
knapsack (the total weight it can hold).

The task is to put the items into the knapsack such that the total value obtained is 
maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional 
selection of items is not allowed. Each item is available only once.


Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
*/

#include <iostream>

using namespace std;

int helper(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &memo)
{
    int n = val.size();

    if (W == 0)
        return 0;
    if (i == n - 1)
    {
        if (wt[i] <= W)
            return val[i];
        return 0;
    }

    if (memo[i][W] != -1)
        return memo[i][W];

    int nonpick = helper(i + 1, W, val, wt, memo);

    int pick = nonpick;
    if (wt[i] <= W)
        pick = helper(i + 1, W - wt[i], val, wt, memo) + val[i];

    return memo[i][W] = max(nonpick, pick);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    vector<vector<int>> memo(n, vector<int>(W + 1, -1));

    int ans = helper(0, W, val, wt, memo);

    return ans;
}

int main()
{
    int W = 7;
    vector<int> val = {10, 8, 6}, wt = {1, 7, 9};

    cout << knapsack(W, val, wt) << endl;

    return 0;
}