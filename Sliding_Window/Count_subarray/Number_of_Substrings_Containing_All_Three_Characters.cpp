/*

1358. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these
characters a, b and c.

Example:

Input: s = "abcabc"
Output: 10

Explanation: The substrings containing at least one occurrence of the characters
a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab",
"cabc" and "abc" (again).

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int min_element(int arr[]) { return min(arr[0], min(arr[1], arr[2])); }
  int numberOfSubstrings(string s) {
    int n = s.length();

    int r = 0, l = 0, cnt = 0;
    int lastSeen[3] = {-1, -1, -1};

    for (r = 0; r < n; r++) {
      lastSeen[s[r] - 'a'] = r;

      bool allSeen =
          lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1;

      if (allSeen) {
        cnt += min_element(lastSeen) + 1;
      }
    }

    return cnt;
  }
};

int main() {

  cout << endl;
  return 0;
}