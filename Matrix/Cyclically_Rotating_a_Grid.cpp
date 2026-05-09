/*

1914. Cyclically Rotating a Grid

*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> layers;

        for(int i = 0; i < min(n, m) / 2; i++){
            vector<int> temp;

            // Go right
            for(int c = i; c < m - i; c++){
                temp.push_back(grid[i][c]);
                // cout << grid[i][c] << " ";
            }

            // down
            for(int r = i + 1; r < n - i; r++){
                temp.push_back(grid[r][m - 1 - i]);
                // cout << grid[r][m - 1 - i] << " ";
            }

            // left
            for(int c = m - 2 - i; c >= 0 + i; c--){
                temp.push_back(grid[n - 1 - i][c]);
                // cout << grid[n - 1 - i][c] << " ";
            }

            // up
            for(int r = n - 2 - i; r >= i + 1; r--){
                temp.push_back(grid[r][i]);
                // cout << grid[r][i] << " ";
            }

            // cout << endl;

            layers.push_back(temp);
        }


        for(int i = 0; i < layers.size(); i++){
            int r = k % layers[i].size();

            reverse(layers[i].begin(), layers[i].begin() + r);
            reverse(layers[i].begin() + r, layers[i].end());
            reverse(layers[i].begin(), layers[i].end());
        }

        vector<vector<int>> matrix(n, vector<int>(m, 0));

        for(int i = 0; i < min(n, m) / 2; i++){
            vector<int> arr = layers[i];
            int ptr = 0;

            // Go right
            for(int c = i; c < m - i; c++){
                // temp.push_back(grid[i][c]);
                matrix[i][c] = arr[ptr++];
            }

            // down
            for(int r = i + 1; r < n - i; r++){
                // temp.push_back(grid[r][m - 1 - i]);
                matrix[r][m - 1 - i] = arr[ptr++];
            }

            // left
            for(int c = m - 2 - i; c >= 0 + i; c--){
                // temp.push_back(grid[n - 1 - i][c]);
                matrix[n - 1 - i][c] = arr[ptr++];
            }

            // up
            for(int r = n - 2 - i; r >= i + 1; r--){
                // temp.push_back(grid[r][i]);
                matrix[r][i] = arr[ptr++];
            }
        }

        return matrix;
    }
};

/*

[10,1,4,8],
[6,6,3,10],
[7,4,7,10],
[1,10,6,1],
[2,1,1,10],
[3,8,9,2],
[7,1,10,10],
[7,1,4,9],
[2,2,4,2],
[10,7,5,10]

*/

int main() {


    cout << endl;
    return 0;
}