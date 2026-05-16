// 1482. Minimum Number of Days to Make m Bouquets

#include <iostream>

using namespace std;

class Solution
{
public:
    int makeBouquets(int day, vector<int> &bloomDay, int m, int k)
    {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay)
        {

            if (bloom <= day)
            {
                flowers++;

                if (flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        return bouquets;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        if (m * 1LL * k > n)
            return -1; // required flowers > available flowers

        int maxDays = bloomDay[0];

        for (auto days : bloomDay)
            maxDays = max(days, maxDays);

        int minDays = maxDays;
        int left = 1, right = maxDays;

        while (left <= right)
        {
            int day = left + (right - left) / 2;

            int noOfBouquets = makeBouquets(day, bloomDay, m, k);

            if (noOfBouquets >= m)
            {
                minDays = min(minDays, day);
                right = day - 1;
            }
            else
            {
                left = day + 1;
            }
        }

        return minDays;
    }
};

/*

m: bouquets
k: adjacent flowers need for bouquet
n: folwers in garden


Example 1:
bloomDay = [1,10,3,10,2]
n = 5
m = 3
k = 1

need 3 flowers

days = 1
    no. of flowers grown in garden = 1

days = 2
    no. of flowers grown in garden = 2

days = 3
    no. of flowers grown in garden = 3


Example 3:
bloomDay = [7,7,7,7,12,7,7]
n = 7
m = 2
k = 3

need 6 flowers

day = 1
    no. of flowers grown in garden = 0

day = 2
    no. of flowers grown in garden = 0

day = 3
    no. of flowers grown in garden = 0

day = 4, 5, 6
    no. of flowers grown in garden = 0

day = 7
    no. of flowers grown in garden = 6
    First 3 are adjacent, But other 3 are not adjancent.

day = 8, 9, 10, 11
    no. of flowers grown in garden = 6
    First 3 are adjacent, But other 3 are not adjancent.

day = 12
    no. of flowers grown in garden = 7


Example 4:
bloomDay = [1,10,2,9,3,8,4,7,5,6]
n = 10
m = 4
k = 2

Why my output is 10 not 9(correct output)

Day = 9
flowers = [x, 10, (x,x), (x,x), (x,x), (x,x)]

*/

int main()
{

    cout << endl;
    return 0;
}