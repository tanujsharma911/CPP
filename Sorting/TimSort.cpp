#include <iostream>
#include <vector>
using namespace std;

// Step 1: Simple insertion sort for small arrays
void insertionSort(vector<int> &arr, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Step 2: Merge two sorted parts
void merge(vector<int> &arr, int left, int mid, int right)
{

    stack<int> L, R;

    for (int i = mid; i >= left; i--)
    {
        L.push(arr[i]);
    }
    for (int i = right; i >= mid + 1; i--)
    {
        R.push(arr[i]);
    }

    int i = left;
    while (!L.empty() && !R.empty())
    {
        if (L.top() < R.top())
        {
            arr[i++] = L.top();
            L.pop();
        }
        else
        {
            arr[i++] = R.top();
            R.pop();
        }
    }
    while (!L.empty())
    {
        arr[i++] = L.top();
        L.pop();
    }
    while (!R.empty())
    {
        arr[i++] = R.top();
        R.pop();
    }
}

// Step 3: Recursive TimSort function
void timSort(vector<int> &arr, int left, int right)
{
    // Base case: if array is small, use insertion sort
    if (right - left + 1 <= 32)
    {
        insertionSort(arr, left, right);
        return;
    }

    // Recursive case: divide and conquer
    int mid = left + (right - left) / 2;

    // Recursively sort left half
    timSort(arr, left, mid);

    // Recursively sort right half
    timSort(arr, mid + 1, right);

    // Merge the two sorted halves
    merge(arr, left, mid, right);
}

// Wrapper function
void timSort(vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    timSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};

    cout << "Before: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    timSort(arr);

    cout << "After:  ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}