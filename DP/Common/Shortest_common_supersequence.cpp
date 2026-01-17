/*
 * 1092. Shortest Common Supersequence
 *
 * Given two strings str1 and str2, return the shortest string that has
 * both str1 and str2 as subsequences. If there are multiple valid strings,
 * return any of them.
 *
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 *
 * Input: str1 = "brute", str2 = "groot"
 * Output: "bgruoote" or "gbrooute"
 */

#include <iostream>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1]){
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }

    int lcs = memo[n][m];

    string superSequences = "";

    int i = n, j = m;

    while(i > 0 && j > 0){
        // cout << str1[i] << " " << str2[j] << endl;
        if(str1[i - 1] == str2[j - 1]){
            superSequences += str1[i - 1];

            i--;
            j--;
        }
        else {
            if(memo[i - 1][j] < memo[i][j - 1]){
                superSequences += str2[j - 1];

                j--;
            }
            else {
                superSequences += str1[i - 1];

                i--;
            }
        }
    }

    while(i > 0){
        superSequences += str1[i - 1];

        i--;
    }
    while(j > 0){
        superSequences += str2[j - 1];

        j--;
    }

    reverse(superSequences.begin(), superSequences.end());

    return superSequences;
}

int main()
{
    string str1 = "brute", str2 = "groot";

    cout << shortestCommonSupersequence(str1, str2);


    cout << endl;
    return 0;
}
