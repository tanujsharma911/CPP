#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        cout << i + 1 << " pass: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k];
        }
        cout << endl;
    }
}

void seletionSort(vector<int> arr){
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;

        for (int j = i + 1; j < n ; j++)
        {
            if(arr[mini] > arr[j]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);

        cout << i + 1 << " pass: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k];
        }
        cout << endl;
    }
    
}

void insertionSort(vector<int> arr)
{
    int n = arr.size();

    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && curr < arr[prev])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;

        cout << i << " pass: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k];
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {5, 4, 1, 3, 2};

    // bubbleSort(arr);
    // seletionSort(arr);
    insertionSort(arr);

    return 0;
}