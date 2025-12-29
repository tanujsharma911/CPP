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


Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last
item (value 50, weight 3) for a total value of 80.
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

    vector<int> memo(W + 1, 0);

    // return helper(0, W, val, wt, memo);

    for (int i = wt[0]; i <= W; i++)
    {
        memo[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(W + 1, 0);
        for (int j = 0; j <= W; j++)
        {
            int nonpick = memo[j];

            int pick = nonpick;
            if (wt[i] <= j)
                pick = memo[j - wt[i]] + val[i];

            temp[j] = max(nonpick, pick);
        }
        memo = temp;
    }

    return memo[W];
}

int main()
{
    int W = 5;
    vector<int> val = {10, 40, 30, 50}, wt = {5, 4, 2, 3};

    cout << knapsack(W, val, wt) << endl;

    return 0;
}