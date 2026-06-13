/*

735. Asteroid Collision

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;

        for (auto astro : asteroids)
        {

            if (!s.empty() && astro < 0 && s.top() > 0)
            {
                while (!s.empty() && s.top() > 0 && s.top() < abs(astro))
                {
                    s.pop();
                }

                if (!s.empty() && s.top() == abs(astro))
                {
                    s.pop();
                    continue;
                }

                if (!s.empty() && s.top() > abs(astro))
                {
                    continue;
                }
            }

            s.push(astro);
        }

        vector<int> ans;

        while (!s.empty())
        {
            ans.emplace(ans.begin(), s.top());
            s.pop();
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}