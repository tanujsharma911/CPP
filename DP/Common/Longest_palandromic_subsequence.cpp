/*
 * Print longest palandromic subsequence
 *
 * s1 = "bbbab"
 *
 * ans: bbbb
 *
 * s2 = "bbabcbcab"
 *
 * ans: babcbab or bacbcab
 */

#include <iostream>
using namespace std;

string printLongestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<string>> memo(n + 1, vector<string>(m + 1, ""));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1])
                memo[i][j] = memo[i - 1][j - 1] + text1[i - 1];

            else{
                if(memo[i][j - 1].length() > memo[i - 1][j].length())
                    memo[i][j] = memo[i][j - 1];
                else
                    memo[i][j] = memo[i - 1][j];
            }
        }
    }

    return memo[n][m];
}

string longestPalindromeSubsequence(string s) {
    string rev = s;
    reverse(s.begin(), s.end());

    return printLongestCommonSubsequence(s, rev);

}

int main()
{
    string s = "bbabcbcab";

    cout << longestPalindromeSubsequence(s);


    cout << endl;
    return 0;
}
