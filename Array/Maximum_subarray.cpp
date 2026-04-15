// 53. Maximum Subarray

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < n; i++){
            if(sum < 0){ 
                sum = 0;
            }

            sum += nums[i];

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main() {
    

    cout << endl;
    return 0;
}