/*

907. Sum of Subarray Minimums

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        long long mod = 1e9 + 7;

        vector<int> next_min(n, -1);
        vector<int> prev_min(n, -1);

        stack<int> s_prev;
        stack<int> s_next;

        for (int i = 0; i < n; i++)
        {
            while (!s_prev.empty() && arr[s_prev.top()] >= arr[i])
            {
                s_prev.pop();
            }
            while (!s_next.empty() && arr[s_next.top()] > arr[n - i - 1])
            {
                s_next.pop();
            }

            if (s_prev.empty())
                prev_min[i] = -1;
            else
                prev_min[i] = s_prev.top();

            if (s_next.empty())
                next_min[n - i - 1] = -1;
            else
                next_min[n - i - 1] = s_next.top();

            s_prev.push(i);
            s_next.push(n - i - 1);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            int prev_min_idx = prev_min[i] == -1 ? -1 : prev_min[i];
            int next_min_idx = next_min[i] == -1 ? n : next_min[i];

            int no_element_left = i - prev_min_idx;
            int no_element_right = next_min_idx - i;

            sum = (sum + (arr[i] * 1LL * no_element_left * no_element_right) % mod) % mod;
        }

        return sum;
    }
};

int main()
{

    cout << endl;
    return 0;
}