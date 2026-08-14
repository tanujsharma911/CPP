/*

Subset Sum on Generated Sequence

There are n children standing in a queue, each assigned a number arr[i]. The teacher writes s on
a paper and gives it to the first child.

Each child writes the sum of all numbers already on the paper and arr[i], then passes it to the next child.

Return true if x can be formed by adding some of the numbers written on the paper: else return false.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int s, int x)
    {
        int n = arr.size();

        long long sum = s;
        vector<long long> seq = {sum};

        for (auto a : arr)
        {
            long long next = sum + a;

            if (next > x)
                break;

            seq.push_back(next);

            sum += next;
        }

        long long target = x;

        for (int i = seq.size() - 1; i >= 0; i--)
        {
            if (seq[i] <= target)
                target -= seq[i];

            if (target == 0)
                return true;
        }

        return false;
    }
};

int main()
{

    cout << endl;
    return 0;
}