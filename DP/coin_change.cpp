/*
322. Coin Change / Minimum coins

You are given an integer array coins representing coins of different denominations
and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount
of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

#include <iostream>

using namespace std;

int coinChange(vector<int> &nums, int amount)
{
    int n = nums.size();

    vector<int> memo(amount + 1, 1e8), curr(amount + 1, 1e8);

    // Base case
    for (int i = 0; i <= amount; i++)
    {
        if (i % nums[0] == 0)
        {
            memo[i] = i / nums[0];
            curr[i] = i / nums[0];
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= amount; j++)
        {
            int nonpick = 0 + memo[j];

            int pick = INT_MAX;
            if (nums[i] <= j)
            {
                pick = 1 + curr[j - nums[i]];
            }

            curr[j] = min(nonpick, pick);
        }
        memo = curr;
    }

    return memo[amount] >= 1e8 ? -1 : memo[amount];
}

int main()
{

    return 0;
}