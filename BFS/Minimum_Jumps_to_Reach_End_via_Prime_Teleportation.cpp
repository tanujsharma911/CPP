// 3629. Minimum Jumps to Reach End via Prime Teleportation

#include <iostream>
#include <unordered_set>

using namespace std;

// brute force
class Solution {
public:
    unordered_set<int> primes_in_nums;

    unordered_map<int, vector<int>>
        map; // {index of prime number, {indices of factors}}

    bool isPrime(int n) {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        if (primes_in_nums.count(n))
            return true;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        primes_in_nums.insert(n);
        return true;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;

                    if (nums[j] % nums[i] == 0) {
                        map[i].push_back(j);
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty()) {
            int i = q.front().first;
            int cost = q.front().second;
            q.pop();

            if(i == n - 1) return cost;

            if(map.count(i)){
                for(auto neighbour: map[i]){
                    if(vis[neighbour] == 1) continue;

                    q.push({neighbour, cost + 1});
                    vis[neighbour] = 1;
                }
            }
            if (i - 1 >= 0 && vis[i - 1] == 0) {
                q.push({i - 1, cost + 1});
                vis[i - 1] = 1;
            }
            if (i + 1 < n && vis[i + 1] == 0) {
                q.push({i + 1, cost + 1});
                vis[i + 1] = 1;
            }
        }

        return -1;
    }
};

// better
// using sieve of eratosthenes for finding prime
class Solution {
public:

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> indices;

        int maxElement = 0;
        for(int i = 0; i < n; i++) {
            maxElement = max(maxElement, nums[i]);
            indices[nums[i]].push_back(i);
        }

        vector<bool> used_prime(maxElement + 1, false);
        vector<int> prime(maxElement + 1, 1);
        if (maxElement >= 0) prime[0] = 0;
        if (maxElement >= 1) prime[1] = 0;

        for(int i = 2; i <= sqrt(maxElement); i++){
            if(prime[i] == 1){
                for(int j = i * i; j <= maxElement; j+= i){
                    prime[j] = 0;
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty()) {
            int i = q.front().first;
            int cost = q.front().second;
            q.pop();

            if(i == n - 1) return cost;

            if (prime[nums[i]] && !used_prime[nums[i]]) {
                used_prime[nums[i]] = true;

                for (int j = nums[i]; j <= maxElement; j += nums[i]) {
                    if (indices.count(j)) {
                        for (auto neighbour : indices[j]) {
                            if (vis[neighbour] == 0) {
                                q.push({neighbour, cost + 1});
                                vis[neighbour] = 1;
                            }
                        }
                    }
                }
            }
            if (i - 1 >= 0 && vis[i - 1] == 0) {
                q.push({i - 1, cost + 1});
                vis[i - 1] = 1;
            }
            if (i + 1 < n && vis[i + 1] == 0) {
                q.push({i + 1, cost + 1});
                vis[i + 1] = 1;
            }
        }

        return -1;
    }
};

int main() {


    cout << endl;
    return 0;
}