/*
 * 219. Contains Duplicate II
 * 
 * Given an integer array nums and an integer k, return true 
 * if there are two distinct indices i and j in the array such that 
 * nums[i] == nums[j] and abs(i - j) <= k.
 */

#include <iostream>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> m;

    for(int i = 0; i < n; i++){
        if(m.count(nums[i])){
            if(abs(i - m[nums[i]]) <= k){
                return true;
            }
        }
        m[nums[i]] = i;
    }

    return false;
}

int main()
{



    cout << endl;
    return 0;
}
