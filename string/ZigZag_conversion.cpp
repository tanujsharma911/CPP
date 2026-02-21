/*
6. Zigzag Conversion (Medium)

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/

#include <iostream>
#include <vector>
using namespace std;

string convert(string s, const int n_rows) {
    int n = s.length();

    if(n_rows == 1) return s;

    vector<string> wordRows(n_rows, "");

    wordRows[0] = s.substr(0, 1);

    bool finished = false;

    int p = 1;

    while(!finished){
        if(p >= n) {
            finished = true;
            break;
        }
        for(int pos = 1; pos < n_rows && !finished; pos++){
            if(p >= n) {
                finished = true;
                break;
            }

            wordRows[pos] += s[p++];
        }
        for(int pos = n_rows - 2; pos >= 0 && !finished; pos--){
            if(p >= n) {
                finished = true;
                break;
            }

            wordRows[pos] += s[p++];
        }
    }

    string ans = "";

    for(auto w: wordRows){
        ans += w;
    }

    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";

    string ans = convert(s, 4);

    cout << "Conversion: " << ans;


    cout << endl;
    return 0;
}
