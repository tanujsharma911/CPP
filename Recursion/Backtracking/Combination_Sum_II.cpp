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
class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i, vector<int>& candidates, int target,
                vector<int>& choosenCandidates) {

        int n = candidates.size();

        if(target == 0){
            ans.push_back(choosenCandidates);
            return;
        }

        if(i == n) return;

        // pick
        if(target >= candidates[i]){
            choosenCandidates.push_back(candidates[i]);

            helper(i + 1, candidates, target - candidates[i], choosenCandidates);

            choosenCandidates.pop_back();
        }

        // skip all duplicates before not-pick
        int j = i;
        while(j + 1 < n && candidates[j] == candidates[j + 1])
            j++;

        helper(j + 1, candidates, target, choosenCandidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> choosenCandidates;

        sort(candidates.begin(), candidates.end());

        helper(0, candidates, target, choosenCandidates);

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}