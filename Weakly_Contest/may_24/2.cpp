// accepted

#include <iostream>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

int passwordStrength(string password)
{
    int n = password.length();

    unordered_set<char> chars;

    for (auto c : password)
    {
        chars.insert(c);
    }

    int strength = 0;

    // "!@#$"©leetcode

    for (auto c : chars)
    {
        if ('a' <= c && c <= 'z')
            strength += 1;
        if ('A' <= c && c <= 'Z')
            strength += 2;
        if ('0' <= c && c <= '9')
            strength += 3;
        if (c == '!')
            strength += 5;
        if (c == '@')
            strength += 5;
        if (c == '#')
            strength += 5;
        if (c == '$')
            strength += 5;
    }

    return strength;
}

int main()
{
    string password = "##";

    cout << passwordStrength(password);

    cout << endl;
    return 0;
}