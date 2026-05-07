/*

https://codeforces.com/contest/2031/problem/D

D. Penchick and Desert Rabbit
Codeforces Round 987 (Div. 2)

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while(tests--){
        int n;
        cin >> n;

        vector<int> nums(n);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        vector<int> preMax(n, nums[0]);

        for(int i = 1; i < n; i++){
            preMax[i] = max(nums[i], preMax[i - 1]);
        }

        int sufMin = INT_MAX;
        vector<int> ans = nums;

        for(int i = n - 1; i >= 0; i--){
            if(preMax[i] > sufMin)
                ans[i] = ans[i + 1];
            else
                ans[i] = preMax[i];

            sufMin = min(nums[i], sufMin);
        }

        for(auto num : ans){
            cout << num << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}