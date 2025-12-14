#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    priority_queue<char, vector<char>, greater<char>> q;

    string s;
    cin >> s;

    for (char c : s)
    {
        if (c != '+')
        {
            q.push(c);
        }
    }

    string ans = "";
    while (!q.empty())
    {
        ans.push_back(q.top());
        ans.push_back('+');
        q.pop();
    }
    ans.pop_back();

    cout << ans << endl;

    return 0;
}