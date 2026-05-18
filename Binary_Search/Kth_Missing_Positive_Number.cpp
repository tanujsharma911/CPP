// 1539. Kth Missing Positive Number

#include <iostream>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &nums, int k)
    {
        int n = nums.size();

        int left = 0, right = n - 1;
        int missing;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            missing = nums[mid] - (mid + 1);

            if (missing < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (right == -1)
        {
            return k;
        }

        missing = nums[right] - (right + 1);

        return nums[right] + (k - missing);
    }
};

int main()
{

    cout << endl;
    return 0;
}