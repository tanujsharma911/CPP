/*
 * 3. Longest Substring Without Repeating Characters (Medium)
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 */
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    unordered_map<char, int> m;

    int longest = 0, left = 0;

    for(int right = 0; right < n; right++){
        m[s[right] - 'a']++;

        while(left < right && m[s[right] - 'a'] >= 2){
            m[s[left] - 'a']--;
            left++;
        }

        longest = max(longest, right - left + 1);
    }

    return longest;
}

int main()
{
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);


    cout << endl;
    return 0;
}
