/*

Sieve of Eratosthenes

Given a positive integer n, calculate and return all prime numbers less than or equal to n using
the Sieve of Eratosthenes algorithm.
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

*/

#include <iostream>

using namespace std;

vector<int> sieve(int n) {
    vector<int> prime(n + 1, 1);

    for(int i = 2; i <= sqrt(n); i++){
        if(prime[i] == 1){
            for(int j = i * i; j <= n; j += i){ // starting from i * i because, i * 2 is marked by 2 and i * 3 is marked by 3 and so on
                prime[j] = 0;
            }
        }
    }

    vector<int> ans;

    for(int i = 2; i <= n; i++){
        if(prime[i] == 1) ans.push_back(i);
    }

    return ans;
}

int main() {


    cout << endl;
    return 0;
}