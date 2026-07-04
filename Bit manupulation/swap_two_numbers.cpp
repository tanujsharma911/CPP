#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 15;
    int b = 9;

    swap(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << endl;
    return 0;
}