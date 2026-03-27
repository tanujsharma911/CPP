#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();

        int totalZeros = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                int zeros = 0;

                i++;
                while (i < n && s[i] == '0')
                {
                    zeros++;
                    i++;
                }
                if (i < n && s[i] == '1')
                {
                    totalZeros += zeros;
                    i--;
                }
            }
        }

        cout << totalZeros << endl;
    }
}