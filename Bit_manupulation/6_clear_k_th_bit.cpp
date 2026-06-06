#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int clearIthBit(int n, int k)
{
    return n & (~(1 << k));
}

int main()
{
    cout << (0 & 0) << endl;
    cout << clearIthBit(13, 2);

    cout << endl;
    return 0;
}