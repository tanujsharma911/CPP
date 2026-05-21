/*

1021. Remove Outermost Parentheses


Example 2:

Input: s = "()(()(()))"
Output: "()(())"

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string str)
    {
        int n = str.length();

        stack<char> s;

        string ans = "";

        for (auto c : str)
        {
            if (c == '(')
            {
                if (!s.empty())
                    ans.push_back('(');

                s.push(c);
            }
            else
            {
                s.pop();

                if (!s.empty())
                    ans.push_back(')');
            }
        }

        return ans;
    }
};

/*

Input: s = "(() ()) (()) (() (()))"
Input: s = " () ()   ()   () (()) "
Output: "()()()()(())"

*/

int main()
{

    cout << endl;
    return 0;
}