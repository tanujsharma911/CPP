#include <iostream>
using namespace std;

void permutation(int i, vector<int>& nums, vector<vector<int>>& ans){ // O(n!)
    int n = nums.size();

    if(i == n){
        ans.push_back(nums);
        return;
    }

    for(int k = i; k < n; k++){
        swap(nums[i], nums[k]);
        permutation(i + 1, nums, ans);
        swap(nums[i], nums[k]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations;

    permutation(0, nums, permutations);

    for(auto &arr: permutations){
        for(auto &num: arr){
            cout << num << ", ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}