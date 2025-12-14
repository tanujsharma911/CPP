#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL; // Initialize pointer to NULL to avoid wild pointer
    int n, i;
    float sum = 0, average;

    // Step 1: Ask user for size (n)
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Dynamically allocate memory using malloc()
    arr = (int *) malloc(n * sizeof(int));

    // Check for malloc failure
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Read n integers
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    // Step 4: Compute average
    average = sum / n;

    // Step 5: Print average
    printf("Average = %f", average);

    // Step 6: Free memory: Avoids Memory Leak
    free(arr);

    // arr still points to freed memory — it's now a dangling pointer!
    // So we must set it to NULL to avoid accidental usage.
    arr = NULL; //  Prevents dangling pointer access

    return 0;
}
