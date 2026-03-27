/*
Given a binary array nums and an integer k, return the maximum number of
consecutive 1's in the array if you can flip at most k 0's.



Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

#include <iostream>

using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int left = 0;
    int maxLength = 0;
    int currZeros = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            currZeros++;

        while (currZeros > k)
        {
            if (nums[left] == 0)
                currZeros--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << longestOnes(nums, k) << endl;

    return 0;
}