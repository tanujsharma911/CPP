// 2033. Minimum Operations to Make a Uni-Value Grid

#include <iostream>

using namespace std;

class Solution
{
public:
    // Brute force
    // Time Limit Exceeded 20 / 64 testcases passed
    int minOperations1(vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();

        int rem = grid[0][0] % x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] % x != rem)
                    return -1;
            }
        }

        int minOperations = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // make all same as this element
                // and note the minimum operations
                int target = grid[i][j];

                int operations = 0;

                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
                        int element = grid[r][c];

                        operations += abs((element - target) / x);
                    }
                }

                minOperations = min(operations, minOperations);
            }
        }

        return minOperations;
    }

    int minOperations2(vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> nums;

        int rem = grid[0][0] % x;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] % x != rem)
                    return -1;

                nums.push_back(grid[r][c]);
            }
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int minOperations = 0;
        
        for (int num : nums) {
            minOperations += abs(num - median) / x;
        }
        
        return minOperations;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 4}, {6, 8}};

    Solution s;

    cout << s.minOperations2(grid, 2);

    cout << endl;
    return 0;
}