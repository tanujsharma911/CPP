/*
 * 48. Rotate Image
 */

#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> temp(n, vector<int>(n, 0));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            int new_r = c;
            int new_c = n - 1 - r;

            temp[new_r][new_c] = matrix[r][c];
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            matrix[r][c] = temp[r][c];
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    rotate(matrix);

    cout << endl;
    return 0;
}
