/*
 * Simple if conditions
 */

#include <iostream>
using namespace std;

// int minOperations(string s) {
//     int n = s.length();
    
//     if(n == 1) return 0;
    
//     bool inc = true;
//     bool same = true;
//     bool dec = true;
    
//     for(int i = 0; i < n - 1; i++){
//         if(s[i] > s[i + 1]){
//             inc = false;
//         }
//         if(s[i] != s[i + 1]){
//             same = false;
//         }
//         if(s[i] < s[i + 1]){
//             dec = false;
//         }
//     }
    
//     if(same){
//         return 0;
//     }
//     if(inc){
//         return 0;
//     }
//     if(dec && n == 2){
//         return -1;
//     }
//     if(dec){
//         return 3;
//     }
//     return 2;
// }

int minOperations(string s) {
    int n = s.length();
    
    bool isSorted = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i + 1]){
            isSorted = false;
            break;
        }
    }
    if(isSorted) return 0;

    if(n == 2) return -1;

    char min_c = s[0], max_c = s[0];
    int min_count = 0, max_count = 0;

    for(char c : s) {
        if(c < min_c) min_c = c;
        if(c > max_c) max_c = c;
    }
    for(char c : s) {
        if(c == min_c) min_count++;
        if(c == max_c) max_count++;
    }

    if(s[0] == min_c || s[n - 1] == max_c) return 1;

    if(s[0] == max_c && s[n - 1] == min_c && max_count == 1 && min_count == 1) {
        return 3;
    }
    
    return 2;
}

int main(){
    string s = "dog";

    cout << minOperations(s);
}
