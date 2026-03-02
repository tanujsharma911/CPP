#include <iostream>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int bp = -1;

    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            bp = i;
            break;
        }
    }

    if(bp == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int next_greater = n - 1 - (int) (upper_bound(nums.rbegin(), nums.rend() - bp - 1, nums[bp]) - nums.rbegin());

    swap(nums[bp], nums[next_greater]);

    sort(nums.begin() + bp + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3};
    
    nextPermutation(nums);
    
    for(auto &num: nums){
        cout << num << ", ";
    }
    
    cout << endl;
    return 0;
}