// 14. Longest Common Prefix (Easy)

// g++ Longest_common_prefix.cpp trie.cpp -o Longest_common_prefix && ./Longest_common_prefix

#include <iostream>
// #include "trie.h"

using namespace std;

class TrieNode
{
public:
    char data;
    int size;
    TrieNode *childrens[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        this->size = 0;
        for (int i = 0; i < 26; i++)
            childrens[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\n');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->childrens[index] != NULL)
        {
            child = root->childrens[index];
        }
        else
        {
            child = root->childrens[index] = new TrieNode(word[0]);
            root->size++;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    string prefix()
    {
        if (root->size > 1)
            return "";
        if (root->size == 0)
            return "";

        TrieNode *curr = root;

        string longestPrefix = "";

        while (curr->size == 1)
        {
            if (curr->isTerminal)
                break;

            for (auto child : curr->childrens)
            {
                if (child != NULL)
                {
                    curr = child;
                    longestPrefix.push_back(child->data);
                }
            }
        }

        return longestPrefix;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie t;

        for (auto &s : strs)
        {
            t.insert(s);
        }

        return t.prefix();
    }
};

int main()
{
    vector<string> strs = {"ab", "a"};

    Solution s;

    cout << s.longestCommonPrefix(strs);

    cout << endl;
    return 0;
}