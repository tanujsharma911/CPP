#include <stdio.h>

int main()
{
    int a[] = {1, 3, 5, 7}, n = sizeof(a) / sizeof(a[0]);
    int b[] = {2, 4, 6, 8}, m = sizeof(b) / sizeof(b[0]);
    int c[7], k = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j] && i < n)
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (a[i] > b[j] && j < m)
        {
            c[k] = b[j];
            k++; j++;
        }
        
    }
    while (i < n)
    {
        c[k] = a[i];
        k++; i++;
    }
    while (j < m)
    {
        c[k] = b[j];
        k++; j++;
    }
    
    

    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    

    return 0;
}