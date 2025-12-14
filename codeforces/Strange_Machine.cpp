#include <stdio >
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        bool allA = true;
        for (char c : s)
            if (c == 'B')
                allA = false;

        while (q--)
        {
            long long x;
            cin >> x;

            if (allA)
            {
                cout << x << " ";
                continue;
            }

            long long time = 0;
            int i = 0;
            while (x > 0)
            {
                if (s[i] == 'A')
                    x--;
                else
                    x /= 2;
                i = (i + 1) % n;
                time++;
            }

            cout << time << " ";
        }
        cout << "\n";
    }
    return 0;
}
