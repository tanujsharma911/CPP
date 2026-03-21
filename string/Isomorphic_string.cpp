#include <iostream>
#include <unordered_set>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.length();

    if(n == 1) return true;

    unordered_map<char, char> ms;
    unordered_map<char, char> mt;

    for(int i = 0; i < n; i++){

        if(ms.count(s[i])){
            if(ms.find(s[i])->second != t[i]){
                return false;
            }
        }
        if(mt.find(t[i]) != mt.end() && mt.find(t[i])->second != s[i]){
            return false;
        }
        ms[s[i]] = t[i];
        mt[t[i]] = s[i];
    }

    return true;
}

int main()
{
    string s = "paper", t = "title";

    cout << isIsomorphic(s, t);


    cout << endl;
    return 0;
}
