#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int findTotalTime(vector<int> &A, int B)
{
    int n = A.size();

    int totalTime = 0;

    int prevTime = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < prevTime + B)
        {
            totalTime -= (prevTime + B) - A[i];
        }
        totalTime += B;
        prevTime = A[i];
    }

    return totalTime;
}

int main()
{
    vector<int> A = {1, 2};
    int B = 2;

    cout << findTotalTime(A, B);

    cout << endl;
    return 0;
}