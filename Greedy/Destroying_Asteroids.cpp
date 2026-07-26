// 2126. Destroying Asteroids

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
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