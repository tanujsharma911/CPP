/*

76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.length();
    int m = t.length();

    int startIndex = -1, length = INT_MAX;

    int cnt = 0, r = 0, l = 0;
    unordered_map<char, int> freq;

    for (auto c : t)
      freq[c]++;

    for (r = 0; r < n; r++) {
      freq[s[r]]--;

      if (freq[s[r]] >= 0) {
        cnt++;
      }

      while (cnt == t.length()) {
        if (r - l + 1 < length) {
          startIndex = l;
          length = r - l + 1;
        }

        freq[s[l]]++;
        if (freq[s[l]] > 0)
          cnt--;

        l++;
      }
    }

    if (startIndex == -1)
      return "";

    return s.substr(startIndex, length);
  }
};

int main() {

  cout << endl;
  return 0;
}