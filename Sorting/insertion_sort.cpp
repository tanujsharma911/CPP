/*

1. In each iteration, select an element from the unsorted part of the array using an outer loop.
2. Place this selected element in its correct position within the sorted part of the array.
3. Use an inner loop to shift the remaining elements, if necessary, to accommodate the selected element.
    This involves shifting elements by one position until the selected element can be placed in the
    correct position.
4. Continue this process until the entire array is sorted.

*/

#include <iostream>

using namespace std;

void insertionSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {

        for (int j = i; j >= 1; j--)
        {
            if (nums[j] >= nums[j - 1])
                break;

            swap(nums[j], nums[j - 1]);
        }
    }
}

int main()
{
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    // Print array before sorting
    cout << "Before insertionSort sort: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    insertionSort(nums);

    // Print array after sorting
    cout << "After insertionSort sort: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
    return 0;
}