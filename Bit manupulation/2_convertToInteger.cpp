#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int convertToInteger(string bin)
{
    int n = bin.length();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += pow(2, i) * (bin[n - i - 1] - '0');
    }

    return ans;
}

int main()
{
    cout << convertToInteger("1000");

    cout << endl;
    return 0;
}