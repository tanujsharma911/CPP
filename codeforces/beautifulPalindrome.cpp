#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Checks if the subsequence is non-decreasing
bool isNonDecreasing(const string &p)
{
    for (size_t i = 1; i < p.size(); ++i)
        if (p[i] < p[i - 1])
            return false;
    return true;
}

// Checks if the remaining string is a palindrome
bool isPalindrome(const string &x)
{
    int n = x.size();
    for (int i = 0; i < n / 2; ++i)
        if (x[i] != x[n - 1 - i])
            return false;
    return true;
}

void solve(string s)
{
    int n = s.size();
    int total = 1 << n; // Total combinations of inclusion/exclusion
    for (int mask = 0; mask < total; ++mask)
    {
        string p = "", x = "";
        vector<int> indices;
        for (int i = 0; i < n; ++i)
        {
            if ((mask >> i) & 1)
            {
                p += s[i];
                indices.push_back(i + 1); // 1-based index
            }
            else
            {
                x += s[i];
            }
        }
        if (isNonDecreasing(p) && isPalindrome(x))
        {
            cout << indices.size() << endl;
            for (int idx : indices)
                cout << idx << " ";
            if (!indices.empty())
                cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        solve(s);
    }
    return 0;
}
