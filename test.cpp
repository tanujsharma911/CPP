#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(int i, int currentOr, vector<vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    
    if(i == rows){
        return currentOr;
    }
    
    int minOr = 1e9;

    for(int k = 0; k < cols; k++){
        int orValue = helper(i + 1, grid[i][k] | currentOr, grid);

        minOr = min(orValue, minOr);
    }

    return minOr;
}
int minimumOR(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    return helper(0, 0, grid);
}

int main(){
    vector<vector<int>> grid = {
        {2,6,7},
        {16,23,20},
        {10,9,28}
    };

    cout << minimumOR(grid) << endl;
}