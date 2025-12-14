#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr = NULL; // Avoid wild pointer
    int last;

    // Step 1: Ask user for size n
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Allocate memory using malloc
    arr = (int*) malloc(n * sizeof(int));

    // Step 3: Read n numbers
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    // Step 4: Ask for one more number
    printf("Enter one more element: ");
    scanf("%d", &last);

    // Step 5: Resize memory using realloc

    int *temp = realloc(arr, (n + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(arr); // prevent memory leak if realloc fails
        return 1;
    }

    // Step 6: Add new element
    arr[n] = last;

    // Step 7: Print all elements
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    // Step 8: Free memory and set pointer to NULL
    free(temp);
    temp = NULL;

    return 0;
}
