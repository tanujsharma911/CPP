// Accepted

#include <iostream>
using namespace std;

char getMirror(char c){
    if('0' <= c && c <= '9'){
        return '9' - (c -'0');
    }

    return ('z' - (int)(c - 'a'));
}

int mirrorFrequency(string s) {
    unordered_map<char, int> freq;

    for(char c : s){
        freq[c]++;
    }

    for(auto p : freq){
        cout << p.first << " " << p.second << endl;
    }

    int sum = 0;

    for(auto c : s){
        char m = getMirror(c);

        if(freq.count(m)){
            sum += abs(freq[c] - freq[m]);

            freq[c] = 0;
            freq[m] = 0;
        }
        else {
            sum++;
        }
    }

    return sum;
}

int main()
{
    string s = "byby";

    cout << mirrorFrequency(s) << endl; // 3
    // cout << getMirror('3') << endl; // 3


    cout << endl;
    return 0;
}
