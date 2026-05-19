/*

Minimize Max Distance to Gas Station

We have a horizontal number line. On that number line, we have gas stations at positions
stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d,
the maximum distance between adjacent gas stations, is minimized. We have to find the smallest
possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.

Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into
approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5.
Now the maximum gap left is 6.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canBePlaced(double maxDis, vector<int> &stations, int K)
    {
        int n = stations.size();

        double pos = stations[0];

        for (int i = 1; i < n; i++)
        {
            if (stations[i] - pos > maxDis && K <= 0)
            {
                return false;
            }

            if (stations[i] - pos <= maxDis)
            {
                pos = stations[i];
            }
            else
            {
                K -= floor((stations[i] - pos) / maxDis);
                pos = stations[i];
            }
        }

        return K >= 0;
    }
    double minMaxDist(vector<int> &stations, int K)
    {
        int n = stations.size();

        double left = 0.000001, right = *max_element(stations.begin(), stations.end());

        double minMaxDis = -1;

        while (right - left >= 0.00001)
        {
            double maxDis = left + (double)(right - left) / 2;

            if (canBePlaced(maxDis, stations, K))
            {
                right = maxDis - 0.000001;
                minMaxDis = maxDis;
            }
            else
            {
                left = maxDis + 0.000001;
            }
        }

        return minMaxDis;
    }
};

int main()
{

    cout << endl;
    return 0;
}