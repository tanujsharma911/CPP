#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

bool checkGoodInteger(int n)
{
    int squareSum = 0;
    int digitSum = 0;

    while (n)
    {
        digitSum += n % 10;
        squareSum += pow(n % 10, 2);
        n = n / 10;
    }

    return squareSum - digitSum >= 50;
}

int main()
{
    cout << (checkGoodInteger(19) ? "true" : "false");

    cout << endl;
    return 0;
}