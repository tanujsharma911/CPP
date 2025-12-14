#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // i: 1 -> arr[i]: 2
    // 2 -> 1

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        arr[temp - 1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}