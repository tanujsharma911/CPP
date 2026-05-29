// 3093. Longest Common Suffix Queries

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class TrieNode
{
public:
    TrieNode *childrens[26];
    int sIndex = INT_MAX;
    int sLength = INT_MAX;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            childrens[i] = NULL;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word, int i)
    {
        int length = word.length();

        TrieNode *curr = root;

        for (int i = length - 1; i >= 0; i--)
        {
            int charIdx = word[i] - 'a';

            if (curr->childrens[charIdx] == NULL)
            {
                curr->childrens[charIdx] = new TrieNode();
            }

            curr = curr->childrens[charIdx];

            if (length < curr->sLength)
            {
                curr->sLength = length;
                curr->sIndex = i;
            }
            else if (length == curr->sLength && i < curr->sIndex)
            {
                curr->sIndex = i;
            }
        }
    }

    int longestCommonSuffix(string word)
    {
        int length = word.length();

        TrieNode *curr = root;

        for (int i = length - 1; i >= 0; i--)
        {
            int charIdx = word[i] - 'a';

            if (curr->childrens[charIdx] == NULL)
            {
                break;
            }

            curr = curr->childrens[charIdx];
        }

        return curr->sIndex;
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        Trie t;

        int indexOfSmallest = 0;

        for (int i = 0; i < wordsContainer.size(); i++)
        {
            if (wordsContainer[i].length() < wordsContainer[indexOfSmallest].length())
            {
                indexOfSmallest = i;
            }

            t.insert(wordsContainer[i], i);
        }

        t.root->sIndex = indexOfSmallest;
        t.root->sLength = wordsContainer[indexOfSmallest].length();

        vector<int> ans(wordsQuery.size());

        for (int i = 0; i < wordsQuery.size(); i++)
        {
            ans[i] = t.longestCommonSuffix(wordsQuery[i]);
        }

        return ans;
    }
};

int main()
{
    vector<string> wordsContainer = {"abcdefgh", "poiuygh", "ghghgh"}, wordsQuery = {"gh", "acbfgh", "acbfegh"};

    Solution s;

    vector<int> ans = s.stringIndices(wordsContainer, wordsQuery);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}