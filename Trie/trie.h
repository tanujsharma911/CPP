#ifndef TRIE_H
#define TRIE_H

#include<string>

class TrieNode {
public:
    char data;
    TrieNode* childrens[26];
    bool isTerminal;

    TrieNode(char data);
};

class Trie {
private:
    void insertUtil(TrieNode* root, std::string word);
    bool searchUtil(TrieNode* root, std::string word);
    bool removeUtil(TrieNode* root, std::string word);
    bool startsWithUtil(TrieNode* root, std::string word);

public:
    TrieNode* root;
    Trie();
    void insert(std::string word);
    bool search(std::string word);
    bool remove(std::string word);
    bool startsWith(std::string prefix);
};

#endif