// 216. Combination Sum III

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void helper(int start, int k, int sum, vector<int> &curr, vector<vector<int>> &ans, int n)
    {
        if (k == 0)
        {
            if (sum == n)
            {
                ans.push_back(curr);
            }
            return;
        }

        for (int i = start; i < 10; i++)
        {
            if (i + sum > n)
            {
                break;
            }

            curr.push_back(i);
            helper(i + 1, k - 1, sum + i, curr, ans, n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(1, k, 0, curr, ans, n);

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}