#include "trie.h"

TrieNode::TrieNode(char data)
{
    this->data = data;
    for (int i = 0; i < 26; i++)
        childrens[i] = nullptr;
    isTerminal = false;
}

Trie::Trie()
{
    root = new TrieNode('\n');
}

void Trie::insertUtil(TrieNode *root, std::string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->childrens[index] != nullptr)
    {
        child = root->childrens[index];
    }
    else
    {
        child = root->childrens[index] = new TrieNode(word[0]);
    }
    insertUtil(child, word.substr(1));
}

void Trie::insert(std::string word) { insertUtil(root, word); }

bool Trie::searchUtil(TrieNode *root, std::string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    int index = word[0] - 'a';

    if (root->childrens[index] != NULL)
    {
        return searchUtil(root->childrens[index], word.substr(1));
    }

    return false;
}

bool Trie::search(std::string word)
{
    return searchUtil(root, word);
}

bool Trie::removeUtil(TrieNode *root, std::string word)
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

    int index = word[0] - 'a';

    if (root->childrens[index] != NULL)
    {
        return removeUtil(root->childrens[index], word.substr(1));
    }

    return false;
}

bool Trie::remove(std::string word)
{
    return removeUtil(root, word);
}

bool Trie::startsWithUtil(TrieNode *root, std::string word)
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

bool Trie::startsWith(std::string prefix)
{
    return startsWithUtil(root, prefix);
}