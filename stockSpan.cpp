#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> price = {31, 41, 48, 59, 79};

    int n = price.size();
    vector<int> span(n, 0);
    stack<int> prevhigh;

    for (int i = 0; i < n; i++)
    {
        while (!prevhigh.empty() && price[prevhigh.top()] <= price[i])
        {
            prevhigh.pop();
        }
        if(prevhigh.empty()){
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

    return 0;
}