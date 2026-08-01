// 396. Rotate Function

#include <iostream>

using namespace std;

class Solution {
public:
    // int helper(int k, int& numsSum, vector<int>& nums, vector<int>& memo){
    //     int n = nums.size();

    //     if (k == 0) {
    //         int sum = 0;
    //         for(int i = 0; i < n; i++){
    //             sum += i * nums[i];
    //         }
    //         return sum;
    //     }

    //     if(memo[k] != -1){
    //         return memo[k];
    //     }

    //     return memo[k] = helper(k - 1, numsSum, nums, memo) + numsSum - n * nums[n - k];
    // }
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int numsSum = 0;

        for(int i = 0; i < n; i++){
            numsSum += nums[i];
        }

        vector<int> memo(n, -1);

        // for(int i = 0; i < n; i++){
        //     int sum = helper(i, numsSum, nums, memo);

        //     ans = max(ans, sum);
        // }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += i * nums[i];
        }
        memo[0] = sum;

        int ans = memo[0];

        for(int k = 1; k < n; k++){
            memo[k] = memo[k - 1] + numsSum - n * nums[n - k];

            ans = max(ans, memo[k]);
        }

        return ans;
    }
};

int main() {


    cout << endl;
    return 0;
}