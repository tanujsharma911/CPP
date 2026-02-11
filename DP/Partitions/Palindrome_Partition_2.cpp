/*
132. Palindrome Partitioning II (Hard)

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

aa b a c

 */

#include <iostream>
using namespace std;

bool isPalindrome(int i, int j, string &s){
    int left = i;
    int right = j;

    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int helper(int i, string &s, vector<int>& memo){
    int n = s.length();

    if(i == n){
        return 0;
    }

    if(memo[i] != -1) return memo[i];

    if(isPalindrome(i, n - 1, s)){
        return 0;
    }

    int cuts = 1e9;

    for(int k = i; k < n; k++){

        if(isPalindrome(i, k, s)){
            int cut = 1 + helper(k + 1, s, memo);

            cuts = min(cuts, cut);
        }
    }

    return memo[i] = cuts;
}

int minCut(string s) {
    int n = s.length();

    vector<int> memo(n, -1);

    return helper(0, s, memo);
}

int main()
{
    string s = "leet";

    cout << "s: " << s << endl;
    cout << "Minimum cuts required: " << minCut(s);


    cout << endl;
    return 0;
}
