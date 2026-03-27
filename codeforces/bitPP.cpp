#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        
        if(temp == "X++" || temp == "++X"){
            ans++;
        }
        else {
            ans--;
        }
    }

    cout << ans;
    
    

    return 0;
}