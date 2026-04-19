#include <iostream>
using namespace std;

long long countCommas(long long num) {
    
        long long total = 0;
    
        if(num >= 1000LL) {
            total += num - 1000LL + 1;
        }
    
        if(num >= 1000000LL) {
            total += (num - 1000000 + 1);
        }
    
        if(num >= 1000000000LL) {
            total += num - 1000000000LL + 1;
        }
        
        if(num >= 1000000000000LL) {
            total += (num - 1000000000000LL + 1);
        }
        
        if(num >= 1000000000000000LL) {
            total += (num - 1000000000000000LL + 1);
        }
        
        if(num >= 1000000000000000000LL) {
            total += (num - 1000000000000000000LL + 1);
        }
        
        return total;
}

int main()
{
    // n < 10^15
    long long n = 1004590;
    cout << countCommas(n); // = 1008182


    cout << endl;
    return 0;
}
