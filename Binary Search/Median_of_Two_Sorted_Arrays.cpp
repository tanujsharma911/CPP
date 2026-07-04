/*

4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int left = 0, right = n;

        while (left <= right)
        {

            int cut1 = left + (right - left) / 2;
            int cut2 = ((n + m) / 2) - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (l2 > r1)
            {
                left = cut1 + 1;
            }
            else if (l1 > r2)
            {
                right = cut1 - 1;
            }
            else
            {
                if ((n + m) % 2 == 0)
                    return ((double)max(l1, l2) + min(r1, r2)) / 2;
                else
                    return min(r1, r2);
            }
        }

        return -1.0;
    }
};

/*

x : No. of elements from first array
y : No. of elements from second array

y = (n1 + n2) / 2 - x

Example 1:

[1, 5, 8, 10, 18, 20]                           [2, 3, 6, 7]
n1 = 6                                           n2 = 4

n1 + n2 = 10

y = 5 - x

Let x = 1,
[1][2, 3, 6, 7] - [5, 8, 10, 18, 20][]
l1 -> 1            r1 -> 5
l2 -> 7            r2 -> INT_MAX

[1, 2, 3, 6, 7] - [5, 8, 10, 18, 20]
Not a partition of sorted array

Let x = 2,
[1, 5][2, 3, 6] - [8, 10, 18, 20][7]
l1 -> 5            r1 -> 8
l2 -> 6            r2 -> 7

l1 < r2
l2 < r1

[1, 2, 3, 5, 6] - [7, 8, 10, 18, 20]
partition of sorted array

median = (6 + 7) / 2 = 6.50



1 2 3 5 6 - 7 8 10 18 20

*/

int main()
{

    cout << endl;
    return 0;
}