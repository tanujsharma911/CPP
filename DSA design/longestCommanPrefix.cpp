#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int minLength = INT_MAX;
    string ans;

    for (int i = 0; i < strs.size(); i++)
    {
        int length = strs[i].length();
        minLength = min(minLength, length);
    }

    for (int i = 0; i < minLength; i++)
    {
        ans.push_back(strs[0][i]);
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j][i] == ans[i])
            {
                // cout << ans << " " << strs[j];
            }
            else
            {
                ans.pop_back();
                return ans;
            }
            // cout << endl;
        }
    }

    return ans;
}

int main()
{
    vector<string> strs = {"flaw", "flow", "flow"};
    cout << "Ans: " << longestCommonPrefix(strs) << endl;

    return 0;
}