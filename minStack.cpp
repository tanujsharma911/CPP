#include <iostream>

using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s;

    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.emplace(val, val);
        }
        else
        {
            s.emplace(val, min(val, s.top().second));
        }
    }

    void pop()
    {
        if (!s.empty())
            s.pop();
    }

    int top()
    {
        if (!s.empty())
            return s.top().first;

        return -1;
    }

    int getMin()
    {
        if (!s.empty())
            return s.top().second;

        return -1;
    }
};

int main()
{
    MinStack s;

    s.pop();
    s.push(5);
    s.push(6);
    s.push(-6);
    s.push(-1);
    cout << s.top();

    return 0;
}