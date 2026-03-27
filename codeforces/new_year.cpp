#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int min_val = a, max_val = a;
    if (b < min_val)
        min_val = b;
    if (c < min_val)
        min_val = c;

    if (b > max_val)
        max_val = b;
    if (c > max_val)
        max_val = c;

    cout << max_val - min_val << endl;

    return 0;
}