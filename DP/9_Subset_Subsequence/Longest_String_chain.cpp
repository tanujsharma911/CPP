/*
 * Longest String Chain
 *
 * You are given an array of words where each word consists of lowercase English letters.

 wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere
 in wordA without changing the order of the other characters to make it equal to wordB.

 For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
 A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1
 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is
 trivially a word chain with k == 1.

 Return the length of the longest possible word chain with words chosen from the given list of words.


 Example 1:
 Input: words = ["a","b","ba","bca","bda","bdca"]
 Output: 4
 Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

 Example 2:
 Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 Output: 5
 Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

 Example 3:
 Input: words = ["abcd","dbqca"]
 Output: 1
 Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
 ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

 */

#include <iostream>
using namespace std;

bool compare(string& curr, string& prev){
    int n = curr.length();
    int m = prev.length();

    if(n != m + 1) return false;

    int i = 0, j = 0;

    while(i < n){
        if(j < m && curr[i] == prev[j]){
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    return (i == n) && (j == m);
}
int longestStrChain(vector<string> words) {
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.length() < b.length();});

    int n = words.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for(int i = 1; i < n; i++){

        for(int j = 0; j < i; j++){

            if(compare(words[i], words[j]) && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout << longestStrChain(words);

    cout << endl;
    return 0;
}
