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

        int r = 0, c = cols - 1;

        while (r < rows && c >= 0)
        {
            if (target == matrix[r][c])
                return true;
            else if (target < matrix[r][c])
                c--;
            else
                r++;
        }

        return false;
    }
};

int main()
{

    cout << endl;
    return 0;
}