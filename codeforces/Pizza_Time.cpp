#include <iostream>

using namespace std;

int main() {

    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int n;
        cin >> n;

        cout << (n - 1) / 2 << endl;
    }
    

    return 0;
}