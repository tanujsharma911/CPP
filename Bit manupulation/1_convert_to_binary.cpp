#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

string convertToBinaryStr(int n)
{
    string ans = "";

    while (n)
    {
        ans = to_string(n % 2) + ans;

        n = n / 2;
    }

    return ans;
}

int convertToBinaryInt(int n)
{
    string ans = "";

    while (n)
    {
        ans = to_string(n % 2) + ans;

        n = n / 2;
    }

    return stoi(ans);
}

int main()
{
    cout << convertToBinaryInt(7);

    cout << endl;
    return 0;
}