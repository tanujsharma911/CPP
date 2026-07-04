/*

Aggressive Cows

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool canBePlaced(int minDis, vector<int> &stallsPos, int cows)
    {
        int n = stallsPos.size();

        int cowsPlaced = 1;
        int lastPlacedAt = stallsPos[0];

        for (int i = 1; i < n; i++)
        {
            if (stallsPos[i] - lastPlacedAt >= minDis)
            {
                cowsPlaced++;
                lastPlacedAt = stallsPos[i];
            }

            if (cowsPlaced == cows)
                return true;
        }

        return false;
    }
    int aggressiveCows(vector<int> stallsPos, int cows)
    {
        int n = stallsPos.size();

        sort(stallsPos.begin(), stallsPos.end());

        int left = 1, right = *max_element(stallsPos.begin(), stallsPos.end());

        int ans = INT_MIN;

        while (left <= right)
        {
            int minDis = left + (right - left) / 2;

            if (canBePlaced(minDis, stallsPos, cows))
            {
                left = minDis + 1;
                ans = max(ans, minDis);
            }
            else
            {
                right = minDis - 1;
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