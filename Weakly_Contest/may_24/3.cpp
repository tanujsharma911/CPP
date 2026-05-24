// Accepted

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int minOperations(vector<int> nums)
{
    int n = nums.size();

    int inc_breaks = 0;
    int dec_breaks = 0;
    int zero_idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            zero_idx = i;
        }
        if (nums[i] > nums[(i + 1) % n])
        {
            inc_breaks++;
        }
        if (nums[i] < nums[(i + 1) % n])
        {
            dec_breaks++;
        }
    }

    int min_ops = -1;

    if (inc_breaks <= 1)
    {
        int cost1 = zero_idx;
        int cost2 = n - zero_idx + 2;

        if (zero_idx == 0)
            cost2 = 0;

        int current_min = min(cost1, cost2);
        if (min_ops == -1 || current_min < min_ops)
        {
            min_ops = current_min;
        }
    }

    if (dec_breaks <= 1)
    {
        int cost1 = n - zero_idx;
        int cost2 = zero_idx + 2;

        int current_min = min(cost1, cost2);
        if (min_ops == -1 || current_min < min_ops)
        {
            min_ops = current_min;
        }
    }

    return min_ops;
}

int main()
{
    vector<int> nums = {2, 1, 0, 3};

    cout << minOperations(nums);

    cout << endl;
    return 0;
}