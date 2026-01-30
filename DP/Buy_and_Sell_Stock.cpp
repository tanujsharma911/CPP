/*
 * You are given an integer array prices where prices[i] is the price of a 
 * given stock on the ith day.
 * 
 * On each day, you may decide to buy and/or sell the stock. You can only 
 * hold at most one share of the stock at any time. However, you can sell and 
 * buy the stock multiple times on the same day, ensuring you never hold more 
 * than one share of the stock.
 * 
 * Find and return the maximum profit you can achieve.
 * 
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Total profit is 4.
 * 
 */

#include <iostream>
using namespace std;

int helper(int i, bool canBuy, vector<int>& prices, vector<vector<int>>& memo){
    int n = prices.size();

    if(i == n){
        return 0;
    }

    if(memo[i][canBuy] != -1) return memo[i][canBuy];

    if(canBuy){
        int buyItNow = helper(i + 1, false, prices, memo) - prices[i];
        int doNothing = helper(i + 1, true, prices, memo);

        return memo[i][canBuy] = max(buyItNow, doNothing);
    }
    else {
        int sellLater = helper(i + 1, false, prices, memo);
        int sellNow = prices[i] + helper(i + 1, true, prices, memo);

        return memo[i][canBuy] = max(sellLater, sellNow);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> memo(n, vector<int>(2, -1));

    return helper(0, true, prices, memo);
}

int main()
{
    vector<int> prices = {1,2,3,0,2};

    cout << "Max Profit: " << maxProfit(prices);


    cout << endl;
    return 0;
}
