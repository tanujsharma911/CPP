/*

3699. Number of ZigZag Arrays I

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution1
{
public:
    // inc: 0 = down, 1 = up
    int helper(int i, int prev, bool inc, int n, int l, int r, vector<vector<vector<int>>> &dp)
    {
        int mod = 1e9 + 7;

        if (i == n)
        {
            return 1;
        }

        if (dp[i][prev][inc] != -1)
            return dp[i][prev][inc];

        int cnt = 0;

        if (inc)
        {
            for (int curr = prev + 1; curr <= r; curr++)
            {
                cnt = (cnt + helper(i + 1, curr, 0, n, l, r, dp)) % mod;
            }
        }
        else
        {
            for (int curr = prev - 1; curr >= l; curr--)
            {
                cnt = (cnt + helper(i + 1, curr, 1, n, l, r, dp)) % mod;
            }
        }

        return dp[i][prev][inc] = cnt;
    }
    int zigZagArrays(int n, int l, int r)
    {
        int mod = 1e9 + 7;

        r = r - l + 1;
        l = 1;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(r + 1, vector<int>(2, -1)));

        int cnt = 0;
        for (int x = l; x <= r; x++)
        {
            cnt = (cnt + helper(1, x, 1, n, l, r, dp)) % mod;
        }

        return (cnt * 2) % mod;
    }
};
class Solution2
{
public:
    // inc: 0 = down, 1 = up
    int zigZagArrays(int n, int l, int r)
    {
        int mod = 1e9 + 7;

        r = r - l + 1;
        l = 1;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(r + 1, vector<int>(2, 0)));

        for (int x = 1; x <= r; x++)
        {
            dp[n][x][0] = 1;
            dp[n][x][1] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {

            for (int prev = l; prev <= r; prev++)
            {
                for (int curr = prev + 1; curr <= r; curr++)
                {
                    dp[i][prev][1] = (dp[i][prev][1] + dp[i + 1][curr][0]) % mod;
                }
                for (int curr = l; curr < prev; curr++)
                {
                    dp[i][prev][0] = (dp[i][prev][0] + dp[i + 1][curr][1]) % mod;
                }
            }
        }

        int cnt = 0;

        for (int x = l; x <= r; x++)
        {
            cnt = (cnt + dp[1][x][1]) % mod;
        }

        return (cnt * 2) % mod;
    }
};

class Solution3 {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;

        r = r - l + 1;
        l = 1;

        int dp[2000 + 1][2000 + 1][2] = {0};

        for(int x = 1; x <= r; x++){
            dp[n][x][0] = 1;
            dp[n][x][1] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            int cumSum0[2000 + 1] = {0};
            int cumSum1[2000 + 1] = {0};

            for(int curr = l; curr <= r; curr++){
                cumSum0[curr] = (cumSum0[curr - 1] + dp[i + 1][curr][0]) % mod;
                cumSum1[curr] = (cumSum1[curr - 1] + dp[i + 1][curr][1]) % mod;
            }

            for(int prev = l; prev <= r; prev++){
                dp[i][prev][1] = (cumSum0[r] - cumSum0[prev] + mod) % mod;
                dp[i][prev][0] = cumSum1[prev - 1] % mod;
            }
        }

        int cnt = 0;

        for(int x = l; x <= r; x++){
            cnt = (cnt + dp[1][x][1]) % mod;
        }

        return (cnt * 2) % mod;
    }
};

int main()
{

    cout << endl;
    return 0;
}