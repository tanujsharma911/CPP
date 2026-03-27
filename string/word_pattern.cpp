#include <iostream>
#include <sstream>
using namespace std;

bool wordPattern(string pattern, string s) {
    int n = pattern.length();
    int m = s.length();

    vector<string> words;

    stringstream ss(s);
    string w;
    while (ss >> w) {
        words.push_back(w);
    }

    if(words.size() != n) return false;

    unordered_map<string, char> word_c;
    unordered_map<char, string> c_word;
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        char c = pattern[i];

        if(word_c.count(word)){
            if(word_c[word] != c) return false;
        }
        if(c_word.count(c)){
            if(c_word[c] != word) return false;
        }

        word_c[word] = c;
        c_word[c] = word;
    }

    return true;
}

int main()
{
    string pattern = "aaaa", s = "dog cat cat dog";
    cout << wordPattern(pattern, s);


    cout << endl;
    return 0;
}
