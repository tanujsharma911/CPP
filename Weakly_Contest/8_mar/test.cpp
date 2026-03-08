#include <iostream>
using namespace std;

int minOperations(string s) {
    int n = s.length();
    
    if(n == 1) return 0;
    
    bool inc = true;
    bool same = true;
    bool dec = true;
    
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i + 1]){
            inc = false;
        }
        if(s[i] != s[i + 1]){
            same = false;
        }
        if(s[i] < s[i + 1]){
            dec = false;
        }
    }
    
    if(same){
        return 0;
    }
    if(inc){
        return 0;
    }
    if(dec && n == 2){
        return -1;
    }
    if(dec){
        return 3;
    }
    return 2;
}

int main(){
    string s = "dog";

    cout << minOperations(s);
}
