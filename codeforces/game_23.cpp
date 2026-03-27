#include <iostream>

using namespace std;

int find(int n, int &goal, int count)
{
    if (n == goal)
        return count;
    if (n > goal)
        return INT_MIN;

    int x = find(n * 2, goal, count + 1);
    int y = find(n * 3, goal, count + 1);

    return max(x, y);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int ans = find(n, m, 0);
    if (ans == INT_MIN)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}