/*

3702. Longest Subsequence With Non-Zero Bitwise XOR

You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero.
If no such subsequence exists, return 0.

Example 1:

Input: nums = [1,2,3]
Output: 2

Explanation:
One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:

Input: nums = [0,0,7,0,0,0,7,0,0]
Output: 8


*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int n = nums.size();

        int XOR = 0;

        for (int a : nums)
        {
            XOR = XOR ^ a;
        }

        if (XOR != 0)
            return n;

        int longestLength = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = XOR ^ nums[i];

            if (temp != 0)
            {
                longestLength = max({longestLength, n - 1});
            }
        }

        return longestLength;
    }
};

int main()
{

    cout << endl;
    return 0;
}