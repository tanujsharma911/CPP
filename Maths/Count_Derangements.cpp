
/*
Count Derangements

Given a number n, find the total number of Derangements of elements from 1 to n. 
A Derangement is a permutation of n elements, such that no element appears in its 
original position, i.e., 1 should not be the first element, 2 should not be second, etc. 
For example, [5, 3, 2, 1, 4] is a Derangement of first 5 elements.

Input: n = 3
Output: 2
Explanation: For the set [1, 2, 3], there are only two possible derangements: [2, 3, 1] and [3, 1, 2].
*/

#include <iostream>

using namespace std;


// Formula based
int derangeCount1(int n) {
    if(n == 1) return 0;
    
    vector<int> factorials = {1, 1, 2, 6};
    
    for(int i = 4; i <= n; i++){
        int last = factorials[factorials.size() - 1];
        
        factorials.push_back(last * i);
    }
    
    int ans = 0;
    
    for(int i = 2; i <= n; i++){
        ans += pow(-1, i) * (factorials[n] / factorials[i]);
    }
    
    return ans;
}
// Brute force
int derangeCount2(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    return (n - 1) * (derangeCount2(n - 2) + derangeCount2(n - 1));
}

// Memoization
int derangeCount3Util(int n, vector<int>& dp) {
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];
    
    return dp[n] = (n - 1) * (derangeCount3Util(n - 2, dp) + derangeCount3Util(n - 1, dp));
}
int derangeCount3(int n) {
    vector<int> dp(n + 1, -1);

    return derangeCount3Util(n, dp);
}

// Tabulation
int derangeCount4(int n) {
    vector<int> dp(n + 1, 0);
    
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i = 3; i <= n; i++){
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
    }
    
    return dp[n];
}

// using only two variables
int derangeCount(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    int p1 = 0, p2 = 1, ans;
    
    for(int i = 3; i <= n; i++){
        ans = (i - 1) * (p1 + p2);
        p1 = p2;
        p2 = ans;
    }
    
    return ans;
}

int main() {

    cout << endl;
    return 0;
}