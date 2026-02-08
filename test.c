#include <stdio.h>

int main()
{
    int n, arr[100], sum[100] = {0};

    printf("Enter n number:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int p = 0;

    for (int i = 1; i < n - 1; i++)
    {
        sum[i] = arr[i] + arr[i - 1] + arr[i + 1];
    }

    printf("%d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}