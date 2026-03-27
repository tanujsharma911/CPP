#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int min = 0;
    int max = 0;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] <= arr[min])
        {
            min = i;
        }
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    int ans = (min < max) ? ((n - 1) - min) + max - 1 : ((n - 1) - min) + max;

    // cout << min << " " << max << endl;
    cout << ans << endl;

    return 0;
}