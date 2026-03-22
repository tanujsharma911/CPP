/*
 * 128. Longest Consecutive Sequence
 *
 * Given an unsorted array of integers nums, return the length of the
 * longest consecutive elements sequence.

 Input: nums = [100,4,200,1,3,2]
 Output: 4
 Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 Therefore its length is 4.
 */

#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    
    unordered_set<int> s;
    
    for(auto num: nums){
        s.insert(num);
    }
    
    int longestSeq = 0;
    
    for(auto num : s){
        if(!s.count(num - 1)){
            int currLongestSeq = 1;
            int next_el = num + 1;
            
            while(s.count(next_el)){
                currLongestSeq++;
                next_el++;
            }
            
            longestSeq = max(longestSeq, currLongestSeq);
        }
    }
    
    return longestSeq;
}

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    cout << longestConsecutive(nums);


    cout << endl;
    return 0;
}
