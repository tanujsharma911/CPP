#include <iostream>

using namespace std;

int main()
{
    int n;
    bool upper = true;
    bool lower = true;

    scanf("%d", &n);

    int m[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j < 0 && m[i][j] != 0)
            {
                upper = false;
            }
            if (i - j > 0 && m[i][j] != 0)
            {
                lower = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", m[i][j]);
        }
        printf("\n");
    }
    if (upper || lower)
    {
        printf("\nyes");
    }
    else
    {
        printf("\nno");
    }

    return 0;
}