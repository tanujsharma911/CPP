#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> price = {31, 41, 48, 59, 79};

    int n = price.size();
    vector<int> span(n, 0);
    stack<int> prevhigh; // The stack always keeps indices of previous higher prices.

    for (int i = 0; i < n; i++)
    {
        while (!prevhigh.empty() && price[prevhigh.top()] <= price[i])
        {
            prevhigh.pop();
        }
        if (prevhigh.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - prevhigh.top();
        }
        prevhigh.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }

    cout << endl;
    return 0;
}

/*
Stock Span Problem

For each day, stock span =
number of consecutive days (including today)
for which the price was less than or equal to today’s price.
*/