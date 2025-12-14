#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int pressed = 0;

        bool found = false;
        for (int i = 1; i < 10 && !found; i++)
        {
            int x = 0;
            for (int j = 1; j <= 4; j++)
            {
                x = (x * 10) + i;
                pressed += j;

                if (n == x)
                {
                    cout << pressed << endl;
                    break;
                    found = true;
                }
            }
        }
    }

    return 0;
}