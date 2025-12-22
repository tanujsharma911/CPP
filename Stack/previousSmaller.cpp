#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {3, 1, 0, 8, 6};

    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}