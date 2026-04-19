// Accepted

#include <iostream>
using namespace std;

vector<int> findGoodIntegers(int n) {
    vector<int> goodNums;

    unordered_map<int, int> m;

    int limit = cbrt(n);

    for(int b = 1; b <= n; b++){
        for(int a = 1; a <= b; a++){
            double cubeSum = pow(a, 3) + pow(b, 3);

            if(cubeSum <= ((double)(n))){
                m[cubeSum]++;

                if(m[cubeSum] == 2) goodNums.push_back(cubeSum);
            }
        }
    }

    sort(goodNums.begin(), goodNums.end());

    return goodNums;
}

int main()
{
    int n = 4104;

    vector<int> ans = findGoodIntegers(n);

    for(auto num : ans){
        cout << num << endl;
    }


    cout << endl;
    return 0;
}
