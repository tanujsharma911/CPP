#include <iostream>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<pair<int, int>> zeros;

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(matrix[r][c] == 0){
                zeros.push_back({r, c});
            }
        }
    }

    if(zeros.size() == 0) return;

    for(int i = 0; i < zeros.size(); i++){
        auto zero = zeros[i];

        int r = zero.first;
        int c = zero.second;

        for(int right = c + 1; right < cols; right++){

            matrix[r][right] = 0;
        }
        for(int left = c - 1; left >= 0; left--){

            matrix[r][left] = 0;
        }
        for(int up = r - 1; up >= 0; up--){

            matrix[up][c] = 0;
        }
        for(int down = r + 1; down < rows; down++){

            matrix[down][c] = 0;
        }
    }
}

int main()
{



    cout << endl;
    return 0;
}
