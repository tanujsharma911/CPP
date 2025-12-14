#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        x = abs(x);
        y = abs(y);

        string op;
        cin >> op;

        int a = 0, c = 0;

        for (auto ch : op)
        {
            if (ch == '4')
            {
                a++;

                c++;
            }
            else
            {
                a++;

                c += 2;
            }
        }

        // cout << "c: " << c << " a: " << a << endl;
        if (x + y <= c && x <= a && y <= a)
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}