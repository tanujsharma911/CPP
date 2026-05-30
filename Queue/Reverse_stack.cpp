// Reverse a Stack

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverseStack(stack<int> &st)
    {
        queue<int> q;

        while (!st.empty())
        {
            q.push(st.top());

            st.pop();
        }

        while (!q.empty())
        {
            st.push(q.front());

            q.pop();
        }
    }
};

int main()
{

    cout << endl;
    return 0;
}