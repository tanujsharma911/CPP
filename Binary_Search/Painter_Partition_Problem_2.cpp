// The Painter's Partition Problem-II

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canPaint(int maxTime, vector<int> &length, int painters)
    {
        int n = length.size();

        int t = 0;
        int p = 1;

        for (int i = 0; i < n; i++)
        {
            if (length[i] > maxTime)
            {
                return false;
            }

            if (t + length[i] <= maxTime)
            {
                t += length[i];
            }
            else
            {
                t = length[i];
                p++;
            }
        }

        return p <= painters;
    }
    int minTime(vector<int> &length, int painters)
    {
        int n = length.size();

        int left = 1, right = accumulate(length.begin(), length.end(), 0);

        int minMaxTime = -1;

        while (left <= right)
        {
            int maxTime = left + (right - left) / 2;

            if (canPaint(maxTime, length, painters))
            {
                right = maxTime - 1;
                minMaxTime = maxTime;
            }
            else
            {
                left = maxTime + 1;
            }
        }

        return minMaxTime;
    }
};

int main()
{

    cout << endl;
    return 0;
}