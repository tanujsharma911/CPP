#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    cout << "largest integer: " << INT_MAX << endl;
    cout << "smallest integer: " << INT_MIN << endl;

    cout << ~5 << endl;

    cout << endl;
    return 0;
}

/*

Number is stored in 32 bits

First digit (left most) is for sign

Largest integer:
    - First digit will be 0 and other 31 are 1
    - It will be 2^30 + 2^29 + ... + 2^0 = 2^31 - 1 = 2,14,74,83,647

Smallest integer: - 2^31 = -2,14,74,83,648

Operators:

1. & -> AND
2. | -> OR
3. ^ -> XOR
4. ~ (NOT)

~5 = -6
~101 = 1000...00110 (2's C)

5. << (Left Shift)

x << k = x * 2^k

6. >> (Right Shift)

x >> k = x / 2^k


*/