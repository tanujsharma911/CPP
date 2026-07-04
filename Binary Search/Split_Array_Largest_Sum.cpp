/*

410. Split Array Largest Sum

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canSplit(int maxSum, vector<int> &nums, int k)
    {
        int n = nums.size();

        int sum = 0;
        int subArrays = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxSum)
                return false;

            if (sum + nums[i] <= maxSum)
            {
                sum += nums[i];
            }
            else
            {
                subArrays++;
                sum = nums[i];
            }
        }

        return subArrays <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);

        int minMaxSum = INT_MAX;

        while (left <= right)
        {
            int maxSum = left + (right - left) / 2;

            if (canSplit(maxSum, nums, k))
            {
                right = maxSum - 1;
                minMaxSum = min(minMaxSum, maxSum);
            }
            else
            {
                left = maxSum + 1;
            }
        }

        return minMaxSum;
    }
};

int main()
{

    cout << endl;
    return 0;
}