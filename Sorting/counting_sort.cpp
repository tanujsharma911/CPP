#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &arr)
{
    int n = arr.size();

    int max_val = *max_element(arr.begin(), arr.end());

    vector<int> cntArr(max_val + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cntArr[arr[i]]++;
    }

    for (int i = 1; i < max_val + 1; i++)
    {
        cntArr[i] = cntArr[i] + cntArr[i - 1];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

int main()
{
    vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};

    countingSort(arr);

    for (auto num : arr)
    {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}