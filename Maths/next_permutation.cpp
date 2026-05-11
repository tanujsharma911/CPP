#include <iostream>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 1)
        return;

    bool ascending = true;
    bool descending = true;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] >= nums[i])
            ascending = false;
        if (nums[i - 1] < nums[i])
            descending = false;
    }

    if (ascending)
    {
        swap(nums[n - 1], nums[n - 2]);
        return;
    }
    if (descending)
    {
        sort(nums.begin(), nums.end());
        return;
    }

    int dip = n - 2;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            dip = i;
            break;
        }
    }

    int next_greater = n - 1;

    for (int i = n - 1; i > dip; i--)
    {
        if (nums[i] > nums[dip])
        {
            next_greater = i;
            break;
        }
    }

    swap(nums[dip], nums[next_greater]);

    sort(nums.begin() + dip + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    for (auto &num : nums)
    {
        cout << num << ", ";
    }

    cout << endl;
    return 0;
}