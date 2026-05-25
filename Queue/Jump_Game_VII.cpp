// 1871. Jump Game VII

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.length();

        if (s[0] == '1' || s[n - 1] == '1')
            return false;

        int farthest = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            for (int j = max(i + minJump, farthest + 1); j < n && j <= i + maxJump; j++)
            {
                if (s[j] == '1')
                    continue;

                q.push(j);
            }
            farthest = i + maxJump;
        }

        return false;
    }
};

int main()
{

    cout << endl;
    return 0;
}