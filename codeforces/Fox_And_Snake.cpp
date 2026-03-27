#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cols, rows;
    cin >> cols >> rows;

    vector<vector<char>> grid(cols, vector<char>(rows, '.'));

    bool right = true;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows && i % 2 == 0; j++)
        {
            grid[i][j] = '#';
        }
        if (i % 2 != 0 && right)
        {
            grid[i][rows - 1] = '#';
            right = false;
        }
        else if (i % 2 != 0 && !right)
        {
            grid[i][0] = '#';
            right = true;
        }
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}