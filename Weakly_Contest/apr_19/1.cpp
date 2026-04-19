// accepted

#include <iostream>

using namespace std;

int firstStableIndex(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> pre_max = nums;
    vector<int> suf_min = nums;

    for (int i = 1; i < n; i++)
    {
        pre_max[i] = max(nums[i], pre_max[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suf_min[i] = min(nums[i], suf_min[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        int sability = pre_max[i] - suf_min[i];

        if (sability <= k)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {0};
    int k = 0;

    cout << firstStableIndex(nums, k);

    cout << endl;
    return 0;
}