#include <iostream>
using namespace std;

int countCommas(int num) {
    string n = to_string(num);

    if(n.length() < 4) return 0;

    if(n.length() < 7) return num - 1000 + 1;

    if(n.length() < 10) return 2 * (num - 1000000 + 1);

    if(n.length() < 13) return 3 * (num - 1000000000 + 1);
    
    return 0;
}

int main()
{
    // n < 10^5
    int n = 1000001;
    cout << countCommas(n);


    cout << endl;
    return 0;
}
