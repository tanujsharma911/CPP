// 238. Product of Array Except Self

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++){
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int suffix = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix = suffix * nums[i + 1];
            ans[i] = ans[i] * suffix;
        }

        return ans;
    }
};

int main() {
    

    cout << endl;
    return 0;
}