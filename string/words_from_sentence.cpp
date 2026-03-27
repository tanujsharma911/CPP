#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s = "dog cat cat dog";
    vector<string> words;

    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    cout << endl;
    return 0;
}
