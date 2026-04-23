// Not completed

/*
Input:
n = 3
contact[] = {"geeikistest", "geeksforgeeks",
"geeksfortest"}
s = "geeips"
Output:
[
    ["geeikistest", "geeksforgeeks", "geeksfortest"],
    ["geeikistest", "geeksforgeeks," "geeksfortest"],
    ["geeikistest", "geeksforgeeks", "geeksfortest"],
    ["geeikistest"],
    ["0"],
    ["0"]
]
Explaination:
By running the search query oncontact list
for "g" we get: "geeikistest", "geeksforgeeks" and "geeksfortest".

By running the search query on contact list
for "ge" we get: "geeikistest" "geeksforgeeks" and "geeksfortest".

By running the search query on contact list
for "gee" we get: "geeikistest" "geeksforgeeks" and "geeksfortest".

By running the search query on contact list
for "geei" we get: "geeikistest".

No results found
for "geeip", so print "0".

No results found
for "geeips", so print "0".
*/

#include <iostream>

using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *childrens[26];

    TrieNode()
    {
        data = '\n';
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = NULL;
        }
    }
    TrieNode(char c)
    {
        data = c;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = NULL;
        }
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

    bool insertUtil(TrieNode *node, string word)
    {
        if (word.length() == 0)
        {
            node->isTerminal = true;
            return true;
        }

        int index = word[0] - 'a';

        if (node->childrens[index] != nullptr)
        {
            return insertUtil(node->childrens[index], word.substr(1));
        }
        else
        {
            node->childrens[index] = new TrieNode(word[0]);
            return insertUtil(node->childrens[index], word.substr(1));
        }
    }
    bool insert(string word)
    {
        return insertUtil(root, word);
    }

    void searchResultsUtils(string prefix, TrieNode* node, string match, vector<string> &results)
    {

    }

    void searchResults(string prefix, vector<string> &results)
    {
        searchResultsUtils(prefix, root, "", results);
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie t;

    int n = sizeof(contact) / sizeof(contact[0]);

    for (int i = 0; i < n; i++)
    {
        t.insert(contact[i]);
    }

    vector<vector<string>> ans;

    string prefix = "";

    for (int i = 0; i < s.length(); i++)
    {
        prefix.push_back(s[i]);

        vector<string> results;

        t.searchResults(prefix, results);

        ans.push_back(results);
    }

    return ans;
}

int main()
{

    cout << endl;
    return 0;
}