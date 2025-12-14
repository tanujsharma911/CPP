#include <iostream>

using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = end;
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot]);

    return i + 1;
}

void quickSort(int arr[], int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int pivot = partition(arr, st, end);

    for (int i = st; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, st, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {5, 2, 8, 5, 9, 2, 8, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}