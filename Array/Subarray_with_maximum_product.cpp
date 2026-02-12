/*
152. Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.
Note that the product of an array with a single element is the value of that element.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

#include <iostream>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int max_prod = -1e9;

    int currPrefixProd = 1;
    int currSuffixProd = 1;

    for(int i = 0; i < n; i++){
        currPrefixProd *= nums[i];
        currSuffixProd *= nums[n - 1 -i];

        max_prod = max(max_prod, currSuffixProd);
        max_prod = max(max_prod, currPrefixProd);

        if(currSuffixProd == 0) currSuffixProd = 1;
        if(currPrefixProd == 0) currPrefixProd = 1;
    }

    return max_prod;
}

int main()
{
    vector<int> nums = {-2,0,-1};

    cout << "Subarray with Maximum product: " << maxProduct(nums);


    cout << endl;
    return 0;
}
