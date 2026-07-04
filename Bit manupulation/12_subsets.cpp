// 78. Subsets

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        int subsets = 1 << n;

        vector<vector<int>> ans;

        for (int i = 0; i < subsets; i++)
        {
            vector<int> subset;

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}