/*



*/

#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    char a[n][m];

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
      }
    }

    int changes = 0;

    for (int i = 0; i < n - 1; i++)
    {
      if (a[i][m - 1] != 'D')
        changes++;
    }

    for (int i = 0; i < m - 1; i++)
    {
      if (a[n - 1][i] != 'R')
        changes++;
    }

    cout << changes << endl;
  }

  return 0;
}
