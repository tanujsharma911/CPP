#include <iostream>
#include <map>

using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n;

        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            m[x]++;
        }

        int remove = 0;
        for (const auto &pair : m)
        {
            int num = pair.first;
            int freq = pair.second;
            // cout << pair.first << ": " << pair.second << endl;

            if (freq < num)
            {
                remove += freq;
            }
            else if (freq > num)
            {
                remove += freq - num;
            }
        }

        cout << remove << endl;
    }

    return 0;
}