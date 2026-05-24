#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> nums1, vector<int> nums2, vector<vector<int>> &queries)
    {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> nums1_map;

        for (auto x : nums1)
        {
            nums1_map[x]++;
        }

        vector<int> ans;

        for (auto q : queries)
        {
            if (q[0] == 1)
            {
                for (int i = q[1]; i <= q[2]; i++)
                {
                    nums2[i] += q[3];
                }
            }
            else
            {
                int cntPairs = 0;

                for (int i = 0; i < m; i++)
                {
                    if (nums1_map.count(q[1] - nums2[i]))
                    {
                        cntPairs += nums1_map[q[1] - nums2[i]];
                    }
                }

                ans.push_back(cntPairs);
            }
        }

        return ans;
    }
};

/*

You are given two integer arrays nums1 and nums2, and a 2D integer array queries.

Each queries[i] is one of the following types:

[1, x, y, val] – Add val to every element in nums2[x..y].
[2, tot] – Compute the number of pairs (j, k) such that nums1[j] + nums2[k] == tot.
Return an integer array answer, where answer[j] is the number of pairs for the jth query of type 2.©leetcode


*/

int main()
{
    vector<int> nums1 = {2, 5, 8, 4}, nums2 = {1, 3, 8};
    vector<vector<int>> queries = {{2, 9}, {1, 1, 2, 1}, {2, 10}};

    Solution s;

    vector<int> ans = s.numberOfPairs(nums1, nums2, queries);

    for (auto x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}