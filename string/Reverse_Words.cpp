/*

Reverse Words


*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string &str)
    {
        reverse(str.begin(), str.end());
        str.push_back('.');

        string ans = "";
        int lastChar = -1;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.' && lastChar != -1)
            {
                reverse(str.begin() + lastChar, str.begin() + i);
                ans += str.substr(lastChar, i - lastChar);
                ans += '.';
                lastChar = -1;
            }
            else if (str[i] != '.' && lastChar == -1)
            {
                lastChar = i;
            }
        }

        ans.pop_back();

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}