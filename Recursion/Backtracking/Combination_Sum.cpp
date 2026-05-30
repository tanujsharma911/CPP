// 39. Combination Sum

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

/*

candidates:
- distinct integers

target:
- integer

return:
- choosenCandidates[]
- sum of choosenCandidates[i] = target
- No restriction on choosen candidates

*/
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(int i, vector<int> &candidates, int target, vector<int> &choosenCandidates)
    {
        int n = candidates.size();

        if (i == n)
        {
            if (target == 0)
                ans.push_back(choosenCandidates);
            return;
        }

        // Not pick
        helper(i + 1, candidates, target, choosenCandidates);

        // pick
        if (target - candidates[i] >= 0)
        {
            choosenCandidates.push_back(candidates[i]);

            helper(i, candidates, target - candidates[i], choosenCandidates);

            choosenCandidates.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> choosenCandidates;

        helper(0, candidates, target, choosenCandidates);

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}