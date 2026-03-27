#include <iostream>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    // cout << k * l / n;
    int ans = min(l * k / nl, c * d);
    ans = min(p / np, ans);

    cout << ans / n << endl;

    return 0;
}