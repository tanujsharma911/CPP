// 18. 4Sum

#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;

                while (left < right)
                {
                    if (nums[i] + 0LL + nums[j] + nums[left] + nums[right] == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (nums[i] + 0LL + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}