/*

2104. Sum of Subarray Ranges

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> nse(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {

            while (!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }

            if (s.empty())
                nse[i] = n;

            else
                nse[i] = s.top();

            s.push(i);
        }

        return nse;
    }
    vector<int> findPSE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> pse(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {

            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }

            if (s.empty())
                pse[i] = -1;

            else
                pse[i] = s.top();

            s.push(i);
        }

        return pse;
    }
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long mod = 1e9 + 7;

        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {

            long long left_elements = i - pse[i];
            long long right_elements = nse[i] - i;

            sum += arr[i] * 1LL * left_elements * right_elements;
        }

        return sum;
    }
    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> nge(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {

            while (!s.empty() && arr[s.top()] < arr[i])
            {
                s.pop();
            }

            if (s.empty())
                nge[i] = n;

            else
                nge[i] = s.top();

            s.push(i);
        }

        return nge;
    }
    vector<int> findPGE(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> pge(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {

            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
                pge[i] = -1;

            else
                pge[i] = s.top();

            s.push(i);
        }

        return pge;
    }
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        long long mod = 1e9 + 7;

        vector<int> pge = findPGE(arr);
        vector<int> nge = findNGE(arr);

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {

            long long left_elements = i - pge[i];
            long long right_elements = nge[i] - i;

            sum += arr[i] * 1LL * left_elements * right_elements;
        }

        return sum;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        long long sum_of_sub_arr_minimums = sumSubarrayMins(nums);
        long long sum_of_sub_arr_maximums = sumSubarrayMaxs(nums);

        return sum_of_sub_arr_maximums - sum_of_sub_arr_minimums;
    }
};

int main()
{

    cout << endl;
    return 0;
}