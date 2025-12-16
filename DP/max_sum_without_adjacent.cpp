#include <iostream>
#include <vector>

using namespace std;

// int maxSumWithoutAdj_memoisation(int i, vector<int> &nums)
// {

// }

// Tabulation
int maxSumWithoutAdj(int i, vector<int> &nums)
{
    if (i == 0)
        return nums[0];

    int pick = nums[i];
    if (i > 1)
        pick += maxSumWithoutAdj(i - 2, nums);

    int nonPick = maxSumWithoutAdj(i - 1, nums);

    int maxS = max(nonPick, pick);

    return maxS;
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};

    // tabulation
    cout << maxSumWithoutAdj(arr.size() - 1, arr) << endl;

    // memoisation
    // cout << maxSumWithoutAdj_memoisation() << endl;

    return 0;
}

/*

Output: 110

Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

*/