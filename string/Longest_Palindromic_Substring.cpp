#include <iostream>
using namespace std;

bool isPalindrome(int i, int j, string &s, vector<vector<int>> memo){

    if(i >= j) return true;

    if(memo[i][j] != -1) return memo[i][j];

    if(s[i] == s[j]) return memo[i][j] = isPalindrome(i + 1, j - 1, s, memo);

    return memo[i][j] = false;
}

string longestPalindrome(string s) {
    int n = s.size();

    string longest = "";

    vector<vector<int>> memo(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s, memo) && j - i + 1 > longest.length()){
                longest = s.substr(i, j - i + 1);
            }
        }
    }

    return longest;
}

string longestPalindrome_Better(string s){
    int n = s.length();

    if(n <= 1) return s;

    auto expand_from_center = [&](int left, int right){
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    };

    string maxLength = s.substr(0, 1); // first character of s

    for(int i = 0; i < n - 1; i++){
        string odd = expand_from_center(i, i);
        string even = expand_from_center(i, i + 1);

        if(odd.length() > maxLength.length()){
            maxLength = odd;
        }
        if(even.length() > maxLength.length()){
            maxLength = even;
        }
    }

    return maxLength;
}

int main()
{
    string s = "babab";

    cout << longestPalindrome_Better(s);


    cout << endl;
    return 0;
}
