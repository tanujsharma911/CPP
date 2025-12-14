#include <iostream>

using namespace std;

int localMinima(vector<vector<int>> m)
{
    int st = 0;
    int end = m.size() - 1;
    int mid_col = (st + end) / 2;

    while (st <= end)
    {
        mid_col = (st + end) / 2;

        int lowest = 0;
        int x, up, bottom, left, right;

        for (int i = 1; i < m.size(); i++)
        {
            if (m[i][mid_col] < m[lowest][mid_col])
            {
                lowest = i;
            }
        }

        x = m[lowest][mid_col];
        (lowest == 0) ? up = INT_MAX : up = m[lowest - 1][mid_col];
        (lowest == m.size() - 1) ? bottom = INT_MAX : up = m[lowest - 1][mid_col];
        (mid_col == 0) ? left = INT_MAX : left = m[lowest][mid_col - 1];
        (mid_col == m.size() - 1) ? right = INT_MAX : right = m[lowest][mid_col + 1];

        if (x < left && x < right)
        {
            return x;
        }
        else if (x < left && right < x)
        {
            st = mid_col + 1;
        }
        else
        {
            end = mid_col - 1;
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> g = {
        {13, 4, 21, 18, 7},
        {2, 20, 10, 14, 22},
        {17, 6, 25, 1, 11},
        {15, 23, 5, 12, 19},
        {24, 3, 16, 8, 9}};

    cout << localMinima(g) << endl;

    return 0;
}