#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int a, b, n;
        cin >> a >> b >> n;

        int count = 0;

        int prev = min(a, b);
        int curr = max(a, b);

        while(curr <= n){
            count++;
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }

        cout << count << endl;

    }
    

    return 0;
}