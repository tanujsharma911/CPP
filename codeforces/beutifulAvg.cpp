#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for(int t = 0; t < tests; t++){
        int n;
        cin >> n;
        int ans = INT_MIN;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > ans){
                ans = arr[i];
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}