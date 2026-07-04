/*

1901. Find a Peak Element II

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0, right = cols - 1;

        while (left <= right)
        {
            int c = left + (right - left) / 2;

            cout << c << " ";

            for (int r = 0; r < rows; r++)
            {
                int left_el = c == 0 ? -1 : mat[r][c - 1];
                int right_el = c == cols - 1 ? -1 : mat[r][c + 1];
                int top_el = r == 0 ? -1 : mat[r - 1][c];
                int bottom_el = r == rows - 1 ? -1 : mat[r + 1][c];

                if (mat[r][c] > top_el && mat[r][c] > bottom_el)
                {

                    if (mat[r][c] > left_el && mat[r][c] > right_el)
                        return {r, c};
                    else if (left_el > mat[r][c])
                    {
                        right = c - 1;
                        break;
                    }
                    else if (right_el > mat[r][c])
                    {
                        left = c + 1;
                        break;
                    }
                }
            }
        }

        return {-1, -1};
    }
};

/*

[10,20,15]
[21,30,14]
[7, 16,32]

[70 ,50,40,30,20]
[100,1 ,2 ,3 ,4]

[41, 8, 2,48,18]
[16,15, 9, 7,44]
[48,35, 6,38,28]
[ 3, 2,14,15,33]
[39,36,13,46,42]

*/

int main()
{

    cout << endl;
    return 0;
}