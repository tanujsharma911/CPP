// 79. Word Search

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool startMatching(int i, int r, int c, vector<vector<char>> &board, string &word, vector<vector<int>> &vis)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (i == word.length())
        {
            return true;
        }

        bool match = false;

        // left cell
        if (c > 0 && !vis[r][c - 1] && board[r][c - 1] == word[i])
        {
            vis[r][c - 1] = 1;
            if (startMatching(i + 1, r, c - 1, board, word, vis))
            {
                match = true;
            }
            vis[r][c - 1] = 0;
        }

        // right cell
        if (c < cols - 1 && !vis[r][c + 1] && board[r][c + 1] == word[i])
        {
            vis[r][c + 1] = 1;
            if (startMatching(i + 1, r, c + 1, board, word, vis))
            {
                match = true;
            }
            vis[r][c + 1] = 0;
        }

        // upper cell
        if (r > 0 && !vis[r - 1][c] && board[r - 1][c] == word[i])
        {
            vis[r - 1][c] = 1;
            if (startMatching(i + 1, r - 1, c, board, word, vis))
            {
                match = true;
            }
            vis[r - 1][c] = 0;
        }

        // bottom cell
        if (r < rows - 1 && !vis[r + 1][c] && board[r + 1][c] == word[i])
        {
            vis[r + 1][c] = 1;
            if (startMatching(i + 1, r + 1, c, board, word, vis))
            {
                match = true;
            }
            vis[r + 1][c] = 0;
        }

        return match;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == word[0])
                {
                    vis[r][c] = 1;
                    if (startMatching(1, r, c, board, word, vis))
                    {
                        return true;
                    }
                    vis[r][c] = 0;
                }
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