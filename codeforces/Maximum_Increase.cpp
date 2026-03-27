#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev = INT_MIN;
    int ans = 0;
    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;

        if (prev < curr)
        {
            ans++;
        }
        else
        {
            ans = 1;
        }

        maxAns = max(maxAns, ans);
        prev = curr;
    }

    cout << maxAns << endl;

    return 0;
}