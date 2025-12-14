#include <iostream>
using namespace std;

int main() {
    int units;
    cin >> units;
    float amount;

    if (units <= 200)
        amount = units * 0.50;
    else if (units <= 400)
        amount = 100 + (units - 200) * 0.65;
    else if (units <= 600)
        amount = 230 + (units - 400) * 0.80;
    else
        amount = 390 + (units - 600) * 1.00;

    cout << "Amount to be paid: " << amount;
    return 0;
}
