#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void insertAsSorted(stack<int> &st, int el)
    {
        if (st.empty())
        {
            st.push(el);
            return;
        }

        if (st.top() > el)
        {
            int curr = st.top();
            st.pop();

            insertAsSorted(st, el);

            st.push(curr);
        }
        else
        {
            st.push(el);
        }
    }
    void sortStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        int el = st.top();
        st.pop();

        cout << el << endl;

        sortStack(st);

        insertAsSorted(st, el);
    }
};

int main()
{
    stack<int> s;

    s.push(41);
    s.push(3);
    s.push(32);
    s.push(2);
    s.push(11);

    Solution sol;
    sol.sortStack(s);

    cout << "After srting:" << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << endl;
    return 0;
}