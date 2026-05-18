// 875. Koko Eating Bananas

#include <iostream>

using namespace std;

class Solution {
public:
    bool canEatInK(int k, vector<int>& piles, int& h){
        int n = piles.size();

        double totalTimeTaken = 0;

        for(auto bananas : piles){
            totalTimeTaken += ceil((double) bananas / k);
        }

        return totalTimeTaken <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        if(n == 1) return ceil((double) piles[0] / h);

        int maxK = INT_MIN;
        int minK = INT_MAX;

        for(auto &bananas : piles) maxK = max(maxK, bananas);

        int left = 1, right = maxK;


        while(left <= right){
            int k = left + (right - left) / 2;

            if(canEatInK(k, piles, h)){
                minK = k;
                right = k - 1;
            }
            else {
                left = k + 1;
            }
        }

        return minK;
    }
};

int main() {


    cout << endl;
    return 0;
}