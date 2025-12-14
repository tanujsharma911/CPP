#include <iostream>

using namespace std;

int main()
{
    const int n = 6, m = 6;

    int g[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}};

    int y = 0;
    for (int x = 0; x <= m / 2; x++)
    {
        for (int i = x; i < m - x; i++) // right
        {
            cout << g[x][i] << " ";
        }
        for (int i = x + 1; i < n - x; i++) // down
        {
            cout << g[i][m - 1 - x] << " ";
        }
        for (int i = m - 2 - x; i >= 0 + x; i--) // left
        {
            cout << g[n - 1 - x][i] << " ";
        }
        for (int i = n - 2 - x; i > x; i--) // up
        {
            cout << g[i][x] << " ";
        }
    }

    cout << endl;

    return 0;
}