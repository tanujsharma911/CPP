#include <iostream>

using namespace std;

int main() {
    string no;
    cin >> no;

    for (int i = 0; i < no.length(); i++)
    {
        if(i == 0 && no[i] == '9') continue;
        
        if (no[i] - '0' >= 5)
        {
            no[i] = (9 - (no[i] - '0')) + '0';
        }
    }

    cout << no;
    

    return 0;
}