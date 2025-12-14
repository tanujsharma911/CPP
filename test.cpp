#include <iostream>
#include <unordered_set>

using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();

    vector<int> odd(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        odd[i] += (nums[i] % 2 != 0);

        odd[i + 1] = odd[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << odd[i] << " ";
    }

    cout << endl;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if(odd[i] == k){
            ans++;
        }

        int find = odd[i] - k;

        if (m.count(find))
        {
            ans += m[find];
        }

        // s.insert(odd[i]);
        if (m.count(find))
        {
            m[find]++;
        }
        else
        {
            m[find] = 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;

    cout << numberOfSubarrays(nums, k) << endl;

    return 0;
}