#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *marks = NULL; // Avoid wild pointer
    int n, i;

    // Step 1: Ask user for number of students
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Allocate memory using malloc()
    marks = (int*) malloc(n * sizeof(int));

    // Step 3: Check if memory allocation is successful
    if (marks == NULL)
    {
        printf("Memory allocation failed");
        free(marks);
        return 1;
    }

    // Step 4: Read marks
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }

    // Step 5: Display marks
    for (int i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }

    // Step 6: Free memory
    free(marks);

    // Step 7: Set pointer to NULL to avoid dangling pointer
    marks = NULL;

    return 0;
}
