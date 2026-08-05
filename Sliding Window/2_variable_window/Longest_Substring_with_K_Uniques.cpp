/*

Longest Substring with K Uniques

You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring that contains exactly k
distinct characters.

Note : If no such substring exists, return -1.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();

        unordered_map<char, int> freq;

        int l = 0, r = 0, longestSubstr = -1;

        for (r = 0; r < n; r++)
        {
            freq[s[r]]++;

            while (l < r && freq.size() > k)
            {
                freq[s[l]]--;

                if (freq[s[l]] == 0)
                    freq.erase(s[l]);

                l++;
            }

            if (freq.size() == k)
                longestSubstr = max(longestSubstr, r - l + 1);
        }

        return longestSubstr;
    }
};

// s = tvtgv, k = 4

int main()
{

    cout << endl;
    return 0;
}