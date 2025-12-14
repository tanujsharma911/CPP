#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n; i >= 0; i--)
    {
        int j = 0;
        bool inc = true;
        bool ended = false;

        while (j >= 0)
        {
            if (j == n)
            {
                inc = false;
            }

            if (j - i >= 0)
            {
                cout << j - i;
                if ((inc && j - i >= 0) || j - i > 0)
                {
                    cout << " ";
                }
            }
            else if (inc)
                cout << "  ";

            if (inc)
                j++;
            else
                j--;
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        int j = 0;
        bool inc = true;

        while (j >= 0)
        {
            if (j == n)
                inc = false;

            if (j - i >= 0)
            {
                cout << j - i;
                if ((inc && j - i >= 0) || j - i > 0)
                {
                    cout << " ";
                }
            }
            else if (inc)
                cout << "  ";

            if (inc)
                j++;
            else
                j--;
        }
        cout << endl;
    }

    return 0;
}