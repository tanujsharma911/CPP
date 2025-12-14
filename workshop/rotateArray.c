#include <stdio.h>

void leftRotateByOne(int arr[], int size)
{
    int first = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first;
}

int main()
{
    int arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    leftRotateByOne(arr, n);

    // Print the modified array
    printf("Array after left rotation: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}