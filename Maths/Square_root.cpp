// 69. Sqrt(x)

#include <iostream>

using namespace std;

int mySqrt(int x) {
    if(x == 0) return 0;

    int ans = 0;

    int left = 1, right = x;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(mid <= x / mid){
            ans = mid;
            left = mid + 1;
        }
        else if(mid > x / mid){
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    

    cout << endl;
    return 0;
}