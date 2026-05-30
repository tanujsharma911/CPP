// Range Min Max Queries

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

class SegmentTree
{
private:
    int n;
    vector<pair<int, int>> seg; // {min, max}

    pair<int, int> build(int idx, int low, int high, vector<int> &arr)
    {

        if (low == high)
        {
            seg[idx].first = arr[low];
            seg[idx].second = arr[low];

            return {arr[low], arr[low]};
        }

        int mid = (low + high) / 2;

        pair<int, int> left = build(2 * idx + 1, low, mid, arr);
        pair<int, int> right = build(2 * idx + 2, mid + 1, high, arr);

        return {min(left.first, right.first), max(left.second, right.second)};
    }

    pair<int, int> getAnsUtil(int idx, int r_low, int r_high, int q_low, int q_high)
    {
        if (q_low <= r_low && r_high <= q_high)
        {
            return {seg[idx].first, seg[idx].second};
        }
        if (r_high < q_low || q_high < r_low)
        {
            return {INT_MAX, INT_MIN};
        }

        int mid = (r_low + r_high) / 2;

        pair<int, int> left = getAnsUtil(idx * 2 + 1, r_low, mid, q_low, q_high);
        pair<int, int> right = getAnsUtil(idx * 2 + 2, mid + 1, r_high, q_low, q_high);

        return {min(left.first, right.first), max(left.second, right.second)};
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        seg.resize(n * 4);
        build(0, 0, n - 1, arr);
    }

    int getMax(int l, int r)
    {
        return getAnsUtil(0, 0, n - 1, l, r).second;
    }

    int getMin(int l, int r)
    {
        return getAnsUtil(0, 0, n - 1, l, r).first;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 0};

    SegmentTree s(arr);

    cout << endl
         << s.getMax(3, 3);

    cout << endl;
    return 0;
}