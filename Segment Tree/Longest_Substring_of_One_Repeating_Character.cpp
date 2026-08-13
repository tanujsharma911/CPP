/*

2213. Longest Substring of One Repeating Character

You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k
and a 0-indexed array of integer indices queryIndices of length k, both of which are used to
describe k queries.

The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

Return an array lengths of length k where lengths[i] is the length of the longest substring of s
consisting of only one repeating character after the ith query is performed.

Example 1:

Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation:
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc".
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

Example 2:

Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].

*/

#include <iostream>

using namespace std;

class SegmentTree
{
public:
    struct Node
    {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;

        Node() {}

        Node(char c)
        {
            leftChar = rightChar = c;
            prefix = suffix = best = 1;
            len = 1;
        }
    };

    int n;
    vector<Node> seg;

    SegmentTree(string &s)
    {
        n = s.length();
        seg.resize(n * 4);
        build(0, 0, n - 1, s);
    }

    Node merge(Node left, Node right)
    {
        Node res;

        res.len = left.len + right.len;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.best = max(left.best, right.best);

        // Prefix
        res.prefix = left.prefix;

        if (left.prefix == left.len && left.rightChar == right.leftChar)
        {
            res.prefix = left.len + right.prefix;
        }

        // Suffix
        res.suffix = right.suffix;

        if (right.suffix == right.len && left.rightChar == right.leftChar)
        {
            res.suffix = right.len + left.suffix;
        }

        // Crossing substring
        if (left.rightChar == right.leftChar)
        {
            res.best = max(res.best, left.suffix + right.prefix);
        }

        return res;
    }

    Node build(int idx, int lo, int hi, string &s)
    {
        if (lo == hi)
        {
            return seg[idx] = Node(s[lo]);
        }

        int mid = (lo + hi) / 2;

        Node left = build(2 * idx + 1, lo, mid, s);
        Node right = build(2 * idx + 2, mid + 1, hi, s);

        return seg[idx] = merge(left, right);
    }

    Node updateUtil(char newChar, int pos, int idx, int lo, int hi)
    {
        if (pos < lo || pos > hi)
            return seg[idx];

        if (lo == hi)
        {
            return seg[idx] = Node(newChar);
        }

        int mid = (lo + hi) / 2;

        Node left = updateUtil(newChar, pos, 2 * idx + 1, lo, mid);
        Node right = updateUtil(newChar, pos, 2 * idx + 2, mid + 1, hi);

        return seg[idx] = merge(left, right);
    }

    void update(char newChar, int pos)
    {
        updateUtil(newChar, pos, 0, 0, n - 1);
    }

    int getLongestRepeating()
    {
        return seg[0].best;
    }
};

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int> &queryIndices)
    {
        int n = s.length();
        int k = queryIndices.size();

        SegmentTree st(s);

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            char c = queryCharacters[i];
            int idx = queryIndices[i];

            st.update(c, idx);

            int maxLength = st.getLongestRepeating();

            ans.push_back(maxLength);
        }

        return ans;
    }

    // Brute force Solution
    // vector<int> longestRepeating(string s, string queryCharacters,
    // vector<int>& queryIndices) {
    //     int n = s.length();
    //     int k = queryIndices.size();

    //     vector<int> ans;

    //     for(int i = 0; i < k; i++){
    //         char c = queryCharacters[i];
    //         int idx = queryIndices[i];

    //         s[idx] = c;

    //         int left = 0, right = 0;
    //         int maxLength = 0;

    //         for(right = 0; right < n; right++){
    //             if(s[left] != s[right]){
    //                 left = right;
    //             }

    //             maxLength = max(maxLength, right - left + 1);
    //         }

    //         ans.push_back(maxLength);
    //     }

    //     return ans;
    // }
};

int main()
{

    cout << endl;
    return 0;
}