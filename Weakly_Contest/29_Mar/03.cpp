// Not solved

#include <iostream>
using namespace std;

int sortableIntegers(vector<int>& nums) {
    int n = nums.size();

    bool ascending = true;
    bool decreasing = true;

    int divisors_sum = 0;

    for(int k = 2; k <= n; k++){
        if(n % k == 0){
            divisors_sum += k;
        }
    }

    for(int i = 1; i < n; i++){
        if(nums[i - 1] <= nums[i]) continue;

        ascending = false;
        break;
    }

    for(int i = 1; i < n; i++){
        if(nums[i - 1] >= nums[i]) continue;

        decreasing = false;
        break;
    }

    if(ascending) return divisors_sum + 1;

    cout << "Not ascending" << endl;

    if(decreasing) return 0;

    cout << "Not decreasing" << endl;

    return divisors_sum;
}

int main()
{
    vector<int> nums = {5,8};

    cout << sortableIntegers(nums);


    cout << endl;
    return 0;
}
