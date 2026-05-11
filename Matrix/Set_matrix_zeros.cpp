#include <iostream>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> zeros_row(rows, 0);
    vector<int> zeros_col(cols, 0);

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(matrix[r][c] == 0) {
                zeros_row[r] = 1;
                zeros_col[c] = 1;
            }
        }
    }

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(zeros_row[r] || zeros_col[c]) {
                matrix[r][c] = 0;
            }
        }
    }
}

int main()
{



    cout << endl;
    return 0;
}
