/*

1386. Cinema Seat Allocation

A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats,
numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi,
seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group
can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be
assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be
assigned.

Example 1:

Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats
marked in blue are already reserved, and each set of four contiguous seats
marked in orange is assigned to one group.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
    unordered_map<int, int> reservedMask;

    for (int i = 0; i < reservedSeats.size(); i++) {
      int row = reservedSeats[i][0];
      int col = reservedSeats[i][1];

      if (col == 1 || col == 10)
        continue;

      reservedMask[row] |= (1 << col); // set bit `col` to 1
    }

    int total = 0;

    int leftMask = 0b0000111100;  // seats: 2, 3, 4, 5
    int midMask = 0b0011110000;   // seats: 4, 5, 6, 7
    int rightMask = 0b1111000000; // seats: 6, 7, 8, 9

    for (auto &[row, bitmask] : reservedMask) {
      bool leftFree = (bitmask & leftMask) == 0;
      bool midFree = (bitmask & midMask) == 0;
      bool rightFree = (bitmask & rightMask) == 0;

      if (leftFree && rightFree)
        total += 2;
      else if (leftFree || midFree || rightFree)
        total++;
    }

    total += (n - reservedMask.size()) * 2;

    return total;
  }
};

int main() {

  cout << endl;
  return 0;
}
