/*

Median in a row-wise sorted Matrix


*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = INT_MAX, right = INT_MIN;

        for (int r = 0; r < rows; r++)
        {
            left = min(left, mat[r][0]);
            right = max(right, mat[r][cols - 1]);
        }

        auto getSmallerElements = [&](int mid)
        {
            int cnt = 0;

            for (auto row : mat)
            {
                cnt += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }

            return cnt;
        };

        int req = (rows * cols) / 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int smallerElements = getSmallerElements(mid);

            // cout << mid << " " << smallerElements << endl;

            if (smallerElements <= req)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // cout << endl;

        return left;
    }
};

int main()
{

    cout << endl;
    return 0;
}