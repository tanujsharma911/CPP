// 2144. Minimum Cost of Buying Candies With Discount

/*

sort([6,5,7,9,2,2])

= [9,7,6,5,2,2]

(9, 7) -> 6
(5, 2) -> 2


sort([1,2,3])

= [3,2,1]



*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();

        auto comparator = [](auto a, auto b)
        {
            return a > b;
        };

        sort(cost.begin(), cost.end(), comparator);

        int totalCost = 0;

        for (int i = 0; i < n; i += 3)
        {
            totalCost += cost[i];

            if (i + 1 < n)
                totalCost += cost[i + 1];
        }

        return totalCost;
    }
};

int main()
{

    cout << endl;
    return 0;
}