/*

295. Find Median from Data Stream

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxH.empty() || num <= maxH.top())
        {
            maxH.push(num);
        }
        else
        {
            minH.push(num);
        }

        int n = minH.size() + maxH.size();

        if (maxH.size() > minH.size() + 1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if (minH.size() > maxH.size())
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    double findMedian()
    {
        int n = minH.size() + maxH.size();

        if (n % 2 == 0)
        {
            return (minH.top() + maxH.top()) / 2.0;
        }
        else
        {
            return maxH.top();
        }
    }
};

int main()
{

    cout << endl;
    return 0;
}