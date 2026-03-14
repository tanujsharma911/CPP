/*
 * 289. Game of Life (Medium)
 */

#include <iostream>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            int live_neighbours = 0;

            for(int i = 0; i < 8; i++){
                int new_r = r + dr[i];
                int new_c = c + dc[i];

                if(new_r >= rows || new_r <= -1 || new_c >= cols || new_c <= -1) continue;

                if(board[new_r][new_c] & 1) live_neighbours++;
            }

            if(board[r][c]){ // Live cell
                if(live_neighbours == 2 || live_neighbours == 3){
                    board[r][c] = 3;
                }
            }
            else { // Dead cell
                if(live_neighbours == 3){
                    board[r][c] = 2;
                }
            }
        }
    }

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            board[r][c] >>= 1;
        }
    }
}

int main()
{
    vector<vector<int>> board = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
        };

    gameOfLife(board);

    cout << endl;
    return 0;
}
