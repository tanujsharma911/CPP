#include <iostream>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    vector<vector<unordered_set<char>>> sub_grid_set(3, vector<unordered_set<char>>(3));

    vector<unordered_set<char>> rows_set(9);
    vector<unordered_set<char>> cols_set(9);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    int row = (3 * i) + k;
                    int col = (3 * j) + l;

                    char curr_num = board[row][col];

                    if(curr_num == '.') continue;

                    if(sub_grid_set[i][j].count(curr_num)){
                        return false;
                    }
                    if(rows_set[row].count(curr_num)){
                        return false;
                    }
                    if(cols_set[col].count(curr_num)){
                        return false;
                    }

                    sub_grid_set[i][j].insert(curr_num);
                    rows_set[row].insert(curr_num);
                    cols_set[col].insert(curr_num);
                }
            }
        }
    }

    return true;
}

int main()
{
    
    
    
    cout << endl;
    return 0;
}