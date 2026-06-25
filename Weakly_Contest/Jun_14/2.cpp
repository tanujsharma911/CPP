#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int getLength(vector<int> &nums)
{
    int n = nums.size();

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(10, 0);
        int max_f = 0;

        for (int j = i; j < n; j++)
        {
            freq[nums[j]]++;
            max_f = max(max_f, freq[nums[j]]);

            int distinct_elements = 0;

            for (int k = 0; k < 10; k++)
            {
                if (freq[k] > 0)
                {
                    distinct_elements++;
                }
            }

            if (distinct_elements == 1)
            {
                ans = max(ans, j - i + 1);
                continue;
            }

            if (max_f % 2 == 1)
                continue;

            int other_f = -1;
            bool other_f_same = true;

            for (int k = 0; k < 10; k++)
            {
                if (freq[k] == 0 || freq[k] == max_f)
                    continue;

                if (other_f == -1)
                {
                    other_f = freq[k];
                }
                else
                {
                    if (other_f != freq[k])
                    {
                        other_f_same = false;
                        break;
                    }
                }
            }

            if (!other_f_same)
            {
                continue;
            }

            if (other_f_same * 2 == max_f)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 4};

    cout << getLength(nums);

    cout << endl;
    return 0;
}