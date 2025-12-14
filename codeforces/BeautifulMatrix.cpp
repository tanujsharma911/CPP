#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> grid(5, vector<int>(5, 0));
    int x = -1, y = -1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }
    }

    cout << abs(2 - x) + abs(2 - y);

    return 0;
}