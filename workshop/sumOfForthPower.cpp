#include <iostream>

using namespace std;

int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        ans += i * i * i * i;
    }

    cout << ans;

    return 0;
}