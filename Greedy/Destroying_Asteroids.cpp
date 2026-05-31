// 2126. Destroying Asteroids

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // bool tryAllPermutation(int i, int mass, vector<int>& asteroids){
    //     int n = asteroids.size();

    //     if(i == n){
    //         for(int j = 0; j < n; j++){
    //             if(mass < asteroids[j]){
    //                 return false;
    //             }
    //             mass += asteroids[j];
    //         }

    //         return true;
    //     }

    //     bool isDestroyed = false;

    //     for(int j = i; j < n; j++){
    //         swap(asteroids[i], asteroids[j]);

    //         if(tryAllPermutation(i + 1, mass, asteroids)){
    //             isDestroyed = true;
    //         }

    //         swap(asteroids[i], asteroids[j]);
    //     }

    //     return isDestroyed;
    // }
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int n = asteroids.size();

        // do seperation in-place to reduce memory
        vector<int> smaller;
        vector<int> bigger;

        for (auto astro : asteroids)
        {
            if (astro <= mass)
                smaller.push_back(astro);

            else
                bigger.push_back(astro);
        }

        if (smaller.empty())
            return false;

        auto comparator = [](auto a, auto b)
        {
            return a > b;
        };

        sort(smaller.begin(), smaller.end(), comparator);
        sort(bigger.begin(), bigger.end());

        double totalMass = mass;

        for (int i = 0; i < smaller.size(); i++)
        {
            totalMass += smaller[i];
        }

        for (int i = 0; i < bigger.size(); i++)
        {
            if (bigger[i] > totalMass)
                return false;
            totalMass += bigger[i];
        }

        return true;
    }
};

int main()
{

    cout << endl;
    return 0;
}