#include <iostream>

using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s;

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
    MinStack s; // Give minimum element below in stack on every level

    s.push(5);
    s.push(6);
    s.push(-6);
    s.push(-1);
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << s.getMin() << endl;

    return 0;
}