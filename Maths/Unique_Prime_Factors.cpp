/*

Unique Prime Factors in Sorted Order

Given a number n. Find its unique prime factors in increasing order.

Input: n = 100
Output: [2, 5]
Explanation: Unique prime factors of 100 are 2 and 5.

Input: n = 60
Output: [2, 3, 5]
Explanation: Prime factors of 60 are 2, 2, 3, 5. Unique prime factors are 2, 3 and 5.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> primeFac(int n)
    {
        vector<int> ans;

        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                ans.push_back(i);

                while (n % i == 0)
                {
                    n = n / i;
                }
            }
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}