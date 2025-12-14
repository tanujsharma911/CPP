#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        if (weight < 50 && height > 170) {
            count++;
        }
    }

    cout << count;
    return 0;
}
