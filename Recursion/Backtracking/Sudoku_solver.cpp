// 37. Sudoku Solver

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(9, false));
    vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(9, false));
    vector<vector<vector<bool>>> subGrid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));

    vector<pair<int, int>> emptyCells;

    bool sol = false;

    void helper(int i, vector<vector<char>> &board)
    {
        if (i == emptyCells.size())
        {
            sol = true;
            return;
        }

        int r = emptyCells[i].first;
        int c = emptyCells[i].second;

        for (int digit = 0; digit < 9; digit++)
        {
            if (row[r][digit])
                continue;
            if (col[c][digit])
                continue;
            if (subGrid[r / 3][c / 3][digit])
                continue;

            row[r][digit] = true;
            col[c][digit] = true;
            subGrid[r / 3][c / 3][digit] = true;

            board[r][c] = digit + '1';
            helper(i + 1, board);

            if (sol)
                return;

            board[r][c] = '.';
            row[r][digit] = false;
            col[c][digit] = false;
            subGrid[r / 3][c / 3][digit] = false;
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                {
                    emptyCells.push_back({r, c});
                }
                else
                {
                    int digit = board[r][c] - '1';

                    row[r][digit] = true;
                    col[c][digit] = true;
                    subGrid[r / 3][c / 3][digit] = true;
                }
            }
        }

        helper(0, board);
    }
};

int main()
{

    cout << endl;
    return 0;
}