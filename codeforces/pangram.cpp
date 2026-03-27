#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;

    int count[26] = {0};

    for (char c: s)
    {
        int idx = tolower(c) - 'a';

        if (count[tolower(c) - 'a'] >= 1)
        {
            cout << "NO" << endl;
        }
        else {
            count[tolower(c) - 'a']++;
        }
        
    }

    cout << "YES" << endl;
    

    return 0;
}