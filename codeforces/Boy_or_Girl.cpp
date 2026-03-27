#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> set;

    int no_unique = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if(set.find(s[i]) == set.end()){
            no_unique++;
            set.insert(s[i]);
        }
    }

    if(no_unique % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }
    

    return 0;
}