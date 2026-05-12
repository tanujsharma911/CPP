// 229. Majority Element II


#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> el_freq(2, vector<int>(2, 0)); // max size = 2

        for(auto el: nums){
            if(el_freq[0][1] == 0 && el_freq[1][0] != el){
                el_freq[0][0] = el;
                el_freq[0][1] = 1;
            }
            else if(el_freq[0][0] == el){
                el_freq[0][1]++;
            }
            else if(el_freq[1][1] == 0){
                el_freq[1][0] = el;
                el_freq[1][1] = 1;
            }
            else if(el_freq[1][0] == el){
                el_freq[1][1]++;
            }
            else {
                el_freq[0][1]--;
                el_freq[1][1]--;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for(auto el : nums){
            if(el == el_freq[0][0]) cnt1++;
            else if(el == el_freq[1][0]) cnt2++;
        }

        vector<int> ans;

        if(cnt1 > n / 3){
            ans.push_back(el_freq[0][0]);
        }
        if(cnt2 > n / 3){
            ans.push_back(el_freq[1][0]);
        }

        return ans;
    }
};

int main() {


    cout << endl;
    return 0;
}