/*
 * Bitonic is first increasing and then decresing
 *
 * Example 1:
 * nums = [1, 2, 10, 7, 5, 4]
 * Ans: 6
 * Explanation: [1, 2, 10] is increasing and [7, 5, 4] is decreasing
 */

#include <iostream>
using namespace std;

int longestBitonicSequence(vector<int> nums){
    int n = nums.size();

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[i] > nums[prev] && lis[prev] + 1 > lis[i]){
                lis[i] = lis[prev] + 1;
            }
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int prev = n - 1; prev > i; prev--){
            if(nums[i] > nums[prev] && lds[prev] + 1 > lds[i]){
                lds[i] = lds[prev] + 1;
            }
        }
    }

    for(auto it : lis){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : lds){
        cout << it << " ";
    }
    cout << endl;

    int ans = 1;

    for(int i = 0; i < n; i++){
        ans = max(ans, lis[i] + lds[i] - 1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 10, 7, 5, 4};
    // vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    // vector<int> nums = {2,1,4,7,3,2,5};

    cout << longestBitonicSequence(nums);


    cout << endl;
    return 0;
}
