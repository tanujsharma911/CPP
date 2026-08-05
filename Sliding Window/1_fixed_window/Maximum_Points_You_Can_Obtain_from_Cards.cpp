/*

1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated
number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the
row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score
you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However,
choosing the rightmost card first will maximize your total score. The optimal
strategy is to take the three cards on the right, giving a final score of 1 + 6
+ 5 = 12.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();

    int l = 0, r = 0, currSum = 0, totalSum = 0, maxScore = INT_MIN;

    for (int i = 0; i < n; i++) {
      totalSum += cardPoints[i];
    }

    for (r = 0; r < n && r < n - k; r++) {
      currSum += cardPoints[r];
    }

    maxScore = max(maxScore, totalSum - currSum);

    while (r < n) {
      currSum += cardPoints[r];
      currSum -= cardPoints[l];

      maxScore = max(maxScore, totalSum - currSum);

      l++;
      r++;
    }

    return maxScore;
  }
};

/*

[1,2,3,4,5,6,1]

[1,2,3] = 6
[1,2,1] = 4
[1,6,1] = 8
[5,6,1] = 12

*/

int main() {

  cout << endl;
  return 0;
}