/*
52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that 
no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
    Input: n = 4
    Output: 2
    Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
    Input: n = 2
    Output: 0

Example 3:
    Input: n = 1
    Output: 1

*/

#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

bool isSafeToPlace(int r, int c, vector<vector<string>>& board){
    int n = board.size();

    // Check vertical file
    for(int row = 0; row < n; row++){
        if(board[row][c] == "Q") return false;
    }

    // Check up-left diagnoal
    for(int row = r - 1, col = c - 1; row >= 0 && col >= 0; col--, row--){
        if(board[row][col] == "Q") return false;
    }

    // Check up-right diagnoal
    for(int row = r - 1, col = c + 1; row >= 0 && col < n; col++, row--){
        if(board[row][col] == "Q") return false;
    }

    return true;
}

void solve(int r, vector<vector<string>>& board){
    int n = board.size();

    if(r == n) ans++;

    for(int c = 0; c < n; c++){
        if(isSafeToPlace(r, c, board)){
            board[r][c] = "Q";
            solve(r + 1, board);
            board[r][c] = ".";
        }
    }
}

int totalNQueens(int n) {
    vector<vector<string>> board(n, vector<string>(n, "."));

    solve(0, board);

    return ans;
}

int main() {
    

    cout << endl;
    return 0;
}