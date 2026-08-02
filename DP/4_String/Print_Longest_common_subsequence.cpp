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

int main()
{
    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.length();
    int m = s2.length();

    cout << printLongestCommonSubsequence(s1, s2);

    cout << endl;
    return 0;
}
