// Accepted

#include <iostream>

using namespace std;

vector<int> findDegrees(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<int> degrees(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(matrix[i][j] == 1){
                degrees[i]++;
                degrees[j]++;
            }
        }
    }

    return degrees;
}

int main() {
    vector<vector<int>> matrix = {
        {0},
    };

    vector<int> degrees = findDegrees(matrix);

    for(auto num : degrees){
        cout << num << " ";
    }
    

    cout << endl;
    return 0;
}