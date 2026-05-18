// 1345. Jump Game IV

#include <iostream>

using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty())
        {
            int currIndex = q.front().first;
            int jumps = q.front().second;
            q.pop();

            if (currIndex == n - 1)
                return jumps;

            int leftJump = currIndex - 1;
            int rightJump = currIndex + 1;

            if (leftJump >= 0 && !vis[leftJump])
            {
                q.push({leftJump, jumps + 1});
                vis[leftJump] = 1;
            }

            if (rightJump < n && !vis[rightJump])
            {
                q.push({rightJump, jumps + 1});
                vis[rightJump] = 1;
            }

            for (auto sameValueIndex : m[nums[currIndex]])
            {
                if (sameValueIndex == currIndex)
                    continue;
                if (vis[sameValueIndex])
                    continue;

                q.push({sameValueIndex, jumps + 1});
                vis[sameValueIndex] = 1;
            }

            m[nums[currIndex]].clear();
        }

        return -1;
    }
};

int main()
{

    cout << endl;
    return 0;
}