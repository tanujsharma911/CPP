
/*
* Longest Increasing Subsequence
* 
* Given an integer array nums, return the longest strictly increasing subsequence.
*
* Input: nums = [10,9,2,5,3,7,101,18]
* Output: [2, 3, 7, 101] or [2, 5, 7, 101]
*/

#include <iostream>
using namespace std;

vector<int> getLIS(vector<int>& nums){

    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> prev(n, 0);

    for(int i = 0; i < n; i++){
        prev[i] = i;
    }

    int max_i = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;

                prev[i] = j;
            }
        }

        if(dp[max_i] < dp[i]) max_i = i;
    }

    vector<int> ans;
    ans.push_back(nums[max_i]);

    int last = max_i;

    while(nums[prev[last]] != nums[last]){
        ans.push_back(nums[prev[last]]);
        last = prev[last];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
   vector<int> nums = {10,9,2,5,3,7,101,18};

   vector<int> lis = getLIS(nums);

   for(auto it : lis){
       cout << it << " ";
   }


    cout << endl;
    return 0;
}
