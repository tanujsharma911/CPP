/*

K-th element of two Arrays


Given two sorted arrays a[] and b[] and an element k, the task is to find
the element that would be at the kth position of the combined sorted array.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();

        if (n > m)
            return kthElement(nums2, nums1, k);

        int left = max(0, k - m);
        int right = min(n, k);

        while (left <= right)
        {
            int cut1 = left + (right - left) / 2;
            int cut2 = k - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (l1 > r2)
            {
                right = cut1 - 1;
            }
            else if (l2 > r1)
            {
                left = cut1 + 1;
            }
            else
            {
                return max(l1, l2);
            }
        }

        return -1;
    }
};

int main()
{

    cout << endl;
    return 0;
}