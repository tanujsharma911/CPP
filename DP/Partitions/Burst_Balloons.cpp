/*
 * 312. Burst Balloons (Hard)
 *
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a
 * number on it represented by an array nums. You are asked to burst all the balloons.
 * If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
 * If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a
 * balloon with a 1 painted on it.
 * Return the maximum coins you can collect by bursting the balloons wisely.
 *
 * Example 1:
 Input: nums = [3,1,5,8]
 Output: 167
 Explanation:
 nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

 Example 2:
 Input: nums = [1,5]
 Output: 10

 https://thewayofnada.medium.com/how-to-solve-the-burst-balloons-problem-like-a-piece-of-cake-6121f365b1f
 */

 #include <iostream>
 using namespace std;

 int helper(int i, int j, vector<int>& nums, vector<vector<int>>& memo){
    if(i > j) return 0;

    if(memo[i][j] != -1) return memo[i][j];

    int maxi = -1e9;
    for(int k = i; k <= j; k++){
        int cost = nums[i - 1] * nums[k] * nums[j + 1] + helper(i, k - 1, nums, memo) + helper(k + 1, j, nums, memo);
        maxi = max(maxi, cost);
    }
    return memo[i][j] = maxi;
}
int maxCoins(vector<int> nums) {

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();

    vector<vector<int>> memo(n, vector<int>(n, -1));

    return helper(1, n - 2, nums, memo);
}


int main()
{
    vector<int> nums = {3,1,5,8};

    cout << "maximum coins: " << maxCoins(nums);


    cout << endl;
    return 0;
}
