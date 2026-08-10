/*

High Effort vs Low Effort


Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can
be completed on the i-th day by performing a high-effort task and a low-effort task, respectively.

For each day, you may choose exactly one of the following:

Perform no task.
Perform a low-effort task.
Perform a high-effort task, which can only be performed on the first day or if no task was
performed on the previous day.
Return the maximum total number of tasks that can be completed over all days.

Input: h[] = [2, 8, 1], l[] = [1, 2, 1]
Output: 9
Explanation: Pick the high-effort task on day 1 and the low-effort task on day 2. Total = 8 + 1 = 9.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int helper(int i, bool tired, vector<int> &h, vector<int> &l, vector<vector<int>> &memo)
    {
        int n = h.size();

        if (i >= n)
            return 0;

        if (memo[i][tired] != -1)
            return memo[i][tired];

        int no_task = 0 + helper(i + 1, false, h, l, memo);
        int low_task = l[i] + helper(i + 1, true, h, l, memo);

        int high_task = INT_MIN;

        if (i == 0 || !tired)
        {
            high_task = h[i] + helper(i + 1, true, h, l, memo);
        }

        return memo[i][tired] = max(no_task, max(low_task, high_task));
    }
    int maxTask(vector<int> &h, vector<int> &l)
    {
        int n = h.size();

        vector<vector<int>> memo(n, vector<int>(2, -1));

        return helper(0, false, h, l, memo);
    }
};

int main()
{

    cout << endl;
    return 0;
}