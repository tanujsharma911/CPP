/*

402. Remove K Digits

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();

        if (k == n)
            return "0";

        string ans = "";

        for (auto c : num)
        {
            while (!ans.empty() && c < ans.back() && k > 0)
            {
                ans.pop_back();
                k--;
            }

            if (!ans.empty() || c != '0')
            {
                ans.push_back(c);
            }
        }

        while (k > 0 && !ans.empty())
        {
            ans.pop_back();
            k--;
        }

        return (ans.length() == 0) ? "0" : ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}