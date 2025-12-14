#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int ans = 0;
        int n;
        cin >> n;
        int numberOfNegative = 0;

        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        for(int j = 0; j < n; j++){
            if(arr[j] == 0){
                ans += 1;
            }
            else if (arr[j] == -1){
                numberOfNegative++;
            }
        }

        if (numberOfNegative % 2 != 0){
            ans += 2;
        }

        cout << ans << endl;
    }

    return 0;
}