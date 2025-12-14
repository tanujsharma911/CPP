#include <stdio.h>

// Function to check if array is sorted
int isSorted(int arr[], int n)
{
    // TODO: Use a loop to compare each pair of elements
    for (int i = 1; i < n; i++)
    {
        if(arr[i - 1] > arr[i]){
            return 0;
        }
    }

    // If any arr[i] > arr[i+1], return 0 (not sorted)
    // if(*(arr + i) > *(arr + i + 1))

    return 1; // Return 1 if all pairs are in order
}

int main()
{
    int arr[100], n;

    // Step 1: Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 3: Check if sorted
    if (isSorted(arr, n))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
