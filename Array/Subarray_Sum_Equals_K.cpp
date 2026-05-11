// 560. Subarray Sum Equals K

#include <iostream>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        int count = 0;

        unordered_map<int, int> prefix_freq;
        prefix_freq[0] = 1;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (prefix_freq.count(sum - k))
            {
                count += prefix_freq[sum - k];
            }

            prefix_freq[sum]++;
        }

        return count;
    }
};

int main()
{

    cout << endl;
    return 0;
}