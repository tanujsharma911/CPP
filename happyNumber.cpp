#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n)
{
    unordered_set<int> list;

    int curr = n;
    int sum = 0;

    while (list.count(curr) == 0)
    {
        list.insert(curr);
        string currStr = to_string(curr);
        sum = 0;

        cout << currStr << endl;

        for (int i = 0; i < currStr.length(); i++)
        {
            sum += (int)(currStr[i] - '0') * (int)(currStr[i] - '0');
        }

        if (sum == 1)
            return true;

        curr = sum;
    }

    return false;
}

int main()
{
    cout << isHappy(19) << endl;

    return 0;
}