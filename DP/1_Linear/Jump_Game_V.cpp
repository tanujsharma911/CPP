// 1340. Jump Game V

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int helper(int i, vector<int> &arr, int d, vector<int> &memo)
    {
        int n = arr.size();

        if (memo[i] != -1)
            return memo[i];

        int maxJump = 1;

        // left side
        for (int j = i - 1; j >= 0 && i - j <= d && arr[j] < arr[i]; j--)
        {
            int jump = 1 + helper(j, arr, d, memo);

            maxJump = max(maxJump, jump);
        }

        // right side
        for (int j = i + 1; j < n && j - i <= d && arr[j] < arr[i]; j++)
        {
            int jump = 1 + helper(j, arr, d, memo);

            maxJump = max(maxJump, jump);
        }

        return memo[i] = maxJump;
    }
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();

        int maxJump = 0;

        vector<int> memo(n, -1);

        for (int i = 0; i < n; i++)
        {
            int jumps = helper(i, arr, d, memo);

            maxJump = max(jumps, maxJump);
        }

        return maxJump;
    }
};

int main()
{

    cout << endl;
    return 0;
}