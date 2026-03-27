/*
Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset 
answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

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
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
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
   vector<int> nums = {1,2,3};

   vector<int> lis = getLIS(nums);

   for(auto it : lis){
       cout << it << " ";
   }


    cout << endl;
    return 0;
}
