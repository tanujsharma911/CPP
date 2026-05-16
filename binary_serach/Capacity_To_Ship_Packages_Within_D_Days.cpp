#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool checkCondition(int maxCapacity, vector<int> &weights, int days)
    {
        int shipWeight = 0;
        int day = 1;

        for (auto itemWeight : weights)
        {
            if (itemWeight > maxCapacity)
                return false;
            else if (shipWeight + itemWeight <= maxCapacity)
                shipWeight += itemWeight;
            else
            {
                day++;
                shipWeight = itemWeight;
            }
        }

        return day <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 1, right = accumulate(weights.begin(), weights.end(), 0);

        int minCapacity = INT_MAX;

        while (left <= right)
        {
            int capacity = left + (right - left) / 2;

            if (checkCondition(capacity, weights, days))
            {
                minCapacity = min(minCapacity, capacity);
                right = capacity - 1;
            }
            else
            {
                left = capacity + 1;
            }
        }

        return minCapacity;
    }
};

int main()
{

    cout << endl;
    return 0;
}