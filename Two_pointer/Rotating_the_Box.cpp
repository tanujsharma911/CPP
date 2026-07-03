/*

1861. Rotating the Box

stone '#'
stationary obstacle '*'
Empty '.'

Input: boxGrid = [
    ["#","#","*",".","*","."],
    ["#","#","#","*",".","."],
    ["#","#","#",".","#","."]]

Output: [
    [".","#","#"],
    [".","#","#"],
    ["#","#","*"],
    ["#","*","."],
    ["#",".","*"],
    ["#",".","."]]

*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> box(m, vector<char>(n, '.'));

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                box[c][n - 1 - r] = boxGrid[r][c];
            }
        }

        for(int c = 0; c < n; c++){
            int emptyPos = m - 1;

            for(int r = m - 1; r >= 0; r--){
                if(box[r][c] == '*') {
                    emptyPos = r - 1;
                }
                else if(box[r][c] == '#') {
                    char temp = box[r][c];
                    box[r][c] = '.';
                    box[emptyPos][c] = temp;
                    emptyPos--;
                }
            }
        }

        return box;
    }
};

int main() {


    cout << endl;
    return 0;
}