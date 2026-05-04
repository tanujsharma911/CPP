/*
 * 48. Rotate Image
 */

#include <iostream>
using namespace std;

// brute force
void rotate1(vector<vector<int>>& matrix) {
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
/*
in place

1, 2, 3   transpose    1, 4, 7   reverse row    7, 4, 1
4, 5, 6  ----------->  2, 5, 8  ------------->  8, 5, 2
7, 8, 9                3, 6, 9                  9, 6, 3

*/
void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for(int r = 0; r < n; r++){
        for(int c = 0; c <= r; c++){
            swap(matrix[r][c], matrix[c][r]);
        }
    }

    // reverse rows
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n / 2; c++){
            swap(matrix[r][c], matrix[r][n - 1 - c]);
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

    rotate2(matrix);

    cout << endl;
    return 0;
}
