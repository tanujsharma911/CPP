#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++){
        int x;
        cin >> x;

        vector<int> ans;

        int place = 1;

        while(x > 0){
            int curr = x % 10;
            x = x / 10;

            if(curr > 0)
                ans.push_back(curr * place);

            place = place * 10;
        }

        cout << ans.size() << endl;
        for(auto i : ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}