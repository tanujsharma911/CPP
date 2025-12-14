#include <iostream>

using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;

    int total_cost = ((w * (w + 1)) / 2) * k;

    if (total_cost <= n)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << total_cost - n << endl;
    }

    return 0;
}