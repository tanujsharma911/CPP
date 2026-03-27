/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.
*/

#include <iostream>

using namespace std;

bool isSafe(int r, int c, int n, vector<string> &board)
{
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 'Q')
            return false;
    }

    // 2. Check upper-left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // 3. Check upper-right diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}
void helper(int n, int row, vector<vector<string>> &ans, vector<string> &board)
{
    if (n == row)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    { // O(n^2)
        if (isSafe(row, i, n, board))
        {
            board[row][i] = 'Q';
            helper(n, row + 1, ans, board);
            board[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    helper(n, 0, ans, board);

    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(5);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            // cout << ans[i][j] << endl;
            for (auto c : ans[i][j])
                cout << c << " ";

            cout << endl;
        }
        cout << endl;
    }

    return 0;
}