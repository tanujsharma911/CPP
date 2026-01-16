/*
 * Print Longest Palindromic Substring
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 */

#include <algorithm>
#include <iostream>
using namespace std;

string longestCommonSubstrBetter(string& s1, string& s2) { // O(n^2)
    int n = s1.length();
    int m = s2.length();

    vector<vector<string>> memo(n + 1, vector<string>(m + 1, ""));

    string maxCommon = "";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i - 1] == s2[j - 1]){
                memo[i][j] = memo[i - 1][j - 1] + s1[i - 1];

                if(memo[i][j].length() > maxCommon.length())
                    maxCommon = memo[i][j];
            }
        }
    }

    return maxCommon;
}

string longestPalindrome(string s) {
    string rev = s;
    reverse(s.begin(), s.end());

    return longestCommonSubstrBetter(s, rev);
}

int main()
{
    string s = "babad";

    cout << longestPalindrome(s);

    cout << endl;
    return 0;
}
