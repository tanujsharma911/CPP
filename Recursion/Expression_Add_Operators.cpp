// 282. Expression Add Operators

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> ans;
    void dfs(int i, string eq, long result, long prevOprand, string num, int target)
    {
        int n = num.length();

        if (i == n)
        {
            if (result == target)
            {
                ans.push_back(eq);
            }
            return;
        }
        for (int j = i; j < n; j++)
        {
            long currNum = stoll(num.substr(i, j - i + 1));

            if (j > i && num[i] == '0')
                break;

            if (i == 0)
            {
                dfs(j + 1, to_string(currNum), currNum, currNum, num, target);
                continue;
            }

            dfs(j + 1, eq + "+" + to_string(currNum), result + currNum, currNum, num, target);
            dfs(j + 1, eq + "-" + to_string(currNum), result - currNum, -currNum, num, target);
            dfs(j + 1, eq + "*" + to_string(currNum), result - prevOprand + prevOprand * currNum, prevOprand * currNum, num, target);
        }
    }
    vector<string> addOperators(string num, int target)
    {
        dfs(0, "", 0, 0, num, target);
        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}