/*

74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = rows - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid][cols - 1])
            {

                int left_inner = 0, right_inner = cols - 1;

                while (left_inner <= right_inner)
                {
                    int mid_inner = left_inner + (right_inner - left_inner) / 2;

                    if (matrix[mid][mid_inner] == target)
                    {
                        return true;
                    }
                    else if (matrix[mid][mid_inner] < target)
                    {
                        left_inner = mid_inner + 1;
                    }
                    else
                    {
                        right_inner = mid_inner - 1;
                    }
                }

                return false;
            }
            else if (target < matrix[mid][0])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main()
{

    cout << endl;
    return 0;
}