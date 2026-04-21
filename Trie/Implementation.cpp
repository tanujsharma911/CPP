/*
Better than hash map because it uses less space.
*/

#include <iostream>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *childrens[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
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

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->childrens[index] != NULL)
        {
            child = root->childrens[index];
        }
        else
        {
            child = root->childrens[index] = new TrieNode(word[0]);
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if (root->childrens[index] != NULL)
        {
            return searchUtil(root->childrens[index], word.substr(1));
        }

        return false;
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0] - 'A';

        if (root->childrens[index] != NULL)
        {
            return removeUtil(root->childrens[index], word.substr(1));
        }

        return false;
    }
    bool remove(string word)
    {
        return removeUtil(root, word);
    }

    bool startsWithUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';

        if (root->childrens[index] != NULL)
        {
            return startsWithUtil(root->childrens[index], word.substr(1));
        }

        return false;
    }
    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix);
    }
};

int main()
{
    Trie t;

    t.insert("hello");                                       // O(L)
    cout << "Present or not: " << t.search("hello") << endl; // O(L)
    cout << "Removed or not: " << t.remove("hello") << endl; // O(L)
    cout << "Present or not: " << t.search("hello") << endl; // O(L)

    cout << endl;
    return 0;
}