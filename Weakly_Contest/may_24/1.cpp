// accepted

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> limitOccurrences(vector<int> &nums, int k)
{
    int n = nums.size();

    if (k == 0)
        return {};

    vector<int> ans;

    ans.push_back(nums[0]);
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == ans[ans.size() - 1])
        {
            if (cnt >= k)
                continue;
            else
            {
                ans.push_back(nums[i]);
                cnt++;
            }
        }
        else
        {
            ans.push_back(nums[i]);
            cnt = 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 0;

    vector<int> ans = limitOccurrences(nums, k);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}