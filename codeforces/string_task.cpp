#include <iostream>
#include <unordered_set>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string ans = "";

    unordered_set<char> set = {'A', 'a', 'O', 'o', 'Y', 'y', 'E', 'e', 'U', 'u', 'I', 'i'};

    for (char c : s)
    {
        if (set.find(c) == set.end())
        {
            ans.push_back('.');
            ans.push_back(tolower(c));
        }
    }

    cout << ans << endl;

    return 0;
}