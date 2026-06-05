#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

string convertToBinary(int n)
{
    string ans = "";

    while (n)
    {
        ans = to_string(n % 2) + ans;

        n = n / 2;
    }

    return ans;
}

int main()
{
    cout << convertToBinary(7);

    cout << endl;
    return 0;
}