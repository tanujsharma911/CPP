/*
 * 1312. Minimum Insertion Steps to Make a String Palindrome (Hard)
 *
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we do not need any insertions.
 *
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 */


 #include <iostream>
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

int longestPalindromeSubsequence(string s) {
    string rev = s;
    reverse(s.begin(), s.end());

    return longestCommonSubsequence(s, rev);

}
int minInsertions(string s) {
    int n = s.length();

    int palandromeLength = longestPalindromeSubsequence(s);

    return n - palandromeLength;
}

int main()
{
    string s = "mbadm";

    cout << minInsertions(s);


    cout << endl;
    return 0;
}
