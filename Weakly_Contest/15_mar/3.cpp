#include <iostream>
using namespace std;

int longestArithmetic(vector<int>& nums) {
    int n = nums.size();

    int left = 0, right = 2;

    int d = nums[1] - nums[0];
    bool changed = false;
    int max_length = 2;

    cout << "d: " << d << endl;

    while(right < n){
        cout << "l: " << left << " r: " << right << " ";
        if(!changed && nums[right] != nums[left] + (d * (right - left))){
            changed = true;
            cout << "c ";
        }
        else if(changed && nums[right] != nums[left] + (d * (right - left))){
            cout << "r ";
            left = right - 1;
            d = nums[right] - nums[left];
        }

        cout << endl;

        max_length = max(max_length, right - left + 1);
        right++;
    }

    return max_length;
}

int main()
{
    vector<int> nums = {1,2,6,7};

    cout << longestArithmetic(nums);


    cout << endl;
    return 0;
}
