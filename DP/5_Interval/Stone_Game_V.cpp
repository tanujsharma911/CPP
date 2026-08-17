/*

1563. Stone Game V

There are several stones arranged in a row, and each stone has an associated value which
is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row
and right row), then Bob calculates the value of each row which is the sum of the values
of all the stones in this row. Bob throws away the row which has the maximum value, and
Alice's score increases by the value of the remaining row. If the value of the two rows
are equal, Bob lets Alice decide which row will be thrown away. The next round starts
with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5].
The left row has the value 11 and the right row has value 14. Bob throws
away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws
away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob
throws away the right row and Alice's score is now 18 (16 + 2). The game ends
because only one stone is remaining in the row.

Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28

Example 3:

Input: stoneValue = [4]
Output: 0

*/

#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> prefix;

public:
    int helper(int lo, int hi, vector<int> &stoneValue, vector<vector<int>> &memo)
    {
        if (lo == hi)
        {
            return 0;
        }

        if (memo[lo][hi] != -1)
            return memo[lo][hi];

        int max_score = INT_MIN;

        for (int i = lo; i < hi; i++)
        {
            int left_sum = prefix[i + 1] - prefix[lo], right_sum = prefix[hi + 1] - prefix[i + 1];

            if (left_sum < right_sum)
            {
                int left_partition = helper(lo, i, stoneValue, memo);

                int curr_score = left_sum + left_partition;
                max_score = max(max_score, curr_score);
            }
            else if (left_sum > right_sum)
            {
                int right_partition = helper(i + 1, hi, stoneValue, memo);

                int curr_score = right_sum + right_partition;
                max_score = max(max_score, curr_score);
            }
            else
            {
                int left_partition = helper(lo, i, stoneValue, memo);
                int right_partition = helper(i + 1, hi, stoneValue, memo);

                int right_score = right_sum + right_partition, left_score = left_sum + left_partition;
                max_score = max({max_score, left_score, right_score});
            }
        }

        return memo[lo][hi] = max_score;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        prefix.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> memo(n, vector<int>(n, -1));

        return helper(0, n - 1, stoneValue, memo);
    }
};

int main()
{

    cout << endl;
    return 0;
}