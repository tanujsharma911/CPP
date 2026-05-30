/*

22. Generate Parentheses

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

/*

This will fail to generate: (())(())

class Solution {
public:
    unordered_set<string> ans;
    void helper(int i, string sub) {
        if(i == 1){
            ans.insert("()" + sub);
            ans.insert("(" + sub + ")");
            ans.insert(sub + "()");
            return;
        }

        helper(i - 1, "()" + sub);
        helper(i - 1, "(" + sub + ")");
        helper(i - 1, sub + "()");
    }
    vector<string> generateParenthesis(int n) {

        helper(n, "");

        vector<string> s;

        for(auto str : ans){
            s.push_back(str);
        }

        return s;
    }
};

Backtracking is better

*/

class Solution
{
public:
    void backtracking(vector<string> &ans, string str, int open, int close, int n)
    {
        if (str.length() == n * 2)
        {
            ans.push_back(str);
            return;
        }

        if (open < n)
        {
            backtracking(ans, str + "(", open + 1, close, n);
        }

        if (close < open)
        {
            backtracking(ans, str + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;

        backtracking(ans, "", 0, 0, n);

        return ans;
    }
};

int main()
{
    int n = 5;
    cout << n - 5 << endl;
    cout << n - 5 << endl;

    cout << endl;
    return 0;
}