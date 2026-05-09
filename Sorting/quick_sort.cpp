#include <iostream>

using namespace std;

int partition(vector<int>& arr, int start, int end)
{
    int pivot = end - 1;
    int pivot_index = start - 1;

    for(int i = start; i < end - 1; i++){
        if(arr[i] <= arr[pivot]){
            pivot_index++;
            swap(arr[pivot_index], arr[i]);
        }
    }

    swap(arr[pivot], arr[pivot_index + 1]);

    return pivot_index + 1;
}

void quickSort(vector<int>& arr, int st, int end)
{
    if (st >= end - 1)
    {
        return;
    }

    int pivot = partition(arr, st, end);

    quickSort(arr, st, pivot);
    quickSort(arr, pivot + 1, end);
}

int main()
{
    vector<int>arr = {9, 4, 7, 3, 1, 2};
    int n = arr.size();

    quickSort(arr, 0, n);

    cout << "After quick sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}