/*

Friends Pairing Problem

Given n friends, each one can remain single or can be paired up with some other
friend. Each friend can be paired only once. Find out the total number of ways
in which friends can remain single or can be paired up.

*/

#include <iostream>
using namespace std;

class Solution {
public:
  unordered_map<int, int> memo = {{1, 1}, {2, 2}};
  int countFriendsPairings(int n) {
    if (memo.count(n))
      return memo[n];

    return memo[n] = countFriendsPairings(n - 1) +
                     (n - 1) * countFriendsPairings(n - 2);
  }
};

int main() {

  cout << endl;
  return 0;
}
