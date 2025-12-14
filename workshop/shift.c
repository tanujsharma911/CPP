#include <stdio.h>

// Function to perform one left shift
void leftShift(int arr[], int size)
{
    // TODO: Store the first element in a variable
    int first = arr[0];
    // Shift all elements to the left by one
    for(int i = 1; i < size ; i++){
        arr[i - 1] = arr[i];
    }
    // Place the stored first element at the end
    arr[size - 1] = first;
}

// Function to perform one right shift
void rightShift(int arr[], int size)
{
    // TODO: Store the last element in a variable
    int last = arr[size - 1];
    // Shift all elements to the right by one
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    // Place the stored last element at the beginning
    arr[0] = last;
}

// Function to perform multiple shifts
void shiftArray(int arr[], int size, int positions, char direction)
{
    // TODO: Use positions % size to normalize shift count
    positions = positions % size;
    // Use a loop to repeat leftShift or rightShift
    if (size == positions)
    {
        return;
    }
    else if (size == 1)
    {
        return;
    }
    
    else if (direction == 'l' || direction == 'L')
    {
        for (int i = 0; i < positions; i++)
        {
            leftShift(arr, size);
        }
    }
    else if (direction == 'r' || direction == 'R')
    {
        for (int i = 0; i < positions; i++)
        {
            rightShift(arr, size);
        }
    }
}

int main()
{
    int arr[100], n, positions;
    char direction;

    // Step 1: Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    // Step 3: Ask for shift count and direction
    printf("Enter number of positions to shift: ");
    scanf("%d", &positions);

    printf("Enter direction (L for left / R for right): ");
    scanf(" %c", &direction); // Note the space before %c

    // Step 4: Call the shiftArray function
    shiftArray(arr, n, positions, direction);

    // Step 5: Print the modified array
    printf("Array after shifting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
