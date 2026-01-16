/*
 * Longest Common Subsequence
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3 (ace)
 */

#include <iostream>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1])
                memo[i][j] = memo[i - 1][j - 1] + 1;

            else
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
        }
    }

    return memo[n][m];
}

int main()
{
    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.length();
    int m = s2.length();

    cout << longestCommonSubsequence(s1, s2);


    cout << endl;
    return 0;
}
