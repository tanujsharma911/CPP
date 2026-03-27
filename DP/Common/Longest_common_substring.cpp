/*
 * length of the longest common substring
 *
 * Substring is continues
 *
 * Input: s1 = "ABCDGH", s2 = "ACDGHR"
 * Output: 4
 * Explanation: The longest common substring is "CDGH" with a length of 4.
 *
 */

#include <iostream>
using namespace std;

int longestCommonSubstr(string& s1, string& s2) { // O(n^3)
    int n = s1.length();
    int m = s2.length();

    int longestCommonSub = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            int k = 0;
            while(i + k < n && j + k < m){

                if(s1[i + k] != s2[j + k]){
                    break;
                }

                k++;
            }

            longestCommonSub = max(longestCommonSub, k);
        }
    }

    return longestCommonSub;
}

int longestCommonSubstrBetter(string& s1, string& s2) { // O(n^2)
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
    
    int maxCommon = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i - 1] == s2[j - 1]){
                memo[i][j] = memo[i - 1][j - 1] + 1;
                
                maxCommon = max(maxCommon, memo[i][j]);
            }
        }
    }

    return maxCommon;
}

int main()
{
    string s1 = "ABCDGH", s2 = "ACDGHR";

    cout << longestCommonSubstrBetter(s1, s2);

    cout << endl;
    return 0;
}
