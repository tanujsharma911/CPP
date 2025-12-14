#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int *a, int start, int end);
void Merge(int *a, int start, int mid, int end);

int main()
{
    int arr[] = {
        54, 32, 78, 12, 45, 90, 33, 76, 87, 21,
        5, 66, 29, 48, 62, 17, 85, 39, 53, 70,
        31, 44, 95, 28, 40, 15, 92, 63, 99, 24,
        14, 18, 80, 36, 9, 98, 84, 69, 8, 50,
        2, 13, 34, 7, 55, 25, 10, 6, 22, 46,
        58, 61, 19, 67, 11, 73, 27, 3, 81, 38,
        64, 91, 77, 16, 4, 42, 1, 26, 43, 52,
        37, 75, 56, 20, 41, 60, 49, 35, 83, 23,
        71, 93, 30, 86, 47, 97, 65, 68, 74, 94,
        57, 100, 59, 88, 72, 89, 79, 96, 51, 82};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    Merge(arr, start, mid, end);
}

void Merge(int *a, int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;
    vector<int> temp = {};

    while (left <= mid && right <= end)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= end)
    {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i - start];
    }
}