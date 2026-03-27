#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans;

    int ind = 0;
    for (int i = 1; ind < n; i++)
    {

        ans.push_back(s[ind]);
        ind += i;
    }

    cout << ans;

    return 0;
}