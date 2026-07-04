/*

3043. Find the Length of the Longest Common Prefix

Example 1:

Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.

*/

#include <iostream>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // T: O(n * m)
    int longestCommonPrefix_BruteForce(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();

        auto getCommonPrefix = [](int a, int b) -> int { // O(1): Because the loop will go till 12 digit which is const
            string x = to_string(a);
            string y = to_string(b);

            for (int i = 0; i < min(x.length(), y.length()); i++)
            {
                if (x[i] != y[i])
                {
                    return i;
                }
            }

            return min(x.length(), y.length());
        };

        int ans = 0;

        // Compare every possible pair(according to problem) and return the max
        for (auto a : arr1)
        {
            for (auto b : arr2)
            {
                ans = max(ans, getCommonPrefix(a, b));
            }
        }

        return ans;
    }
    // Create every prefix of second array and store that into hash map
    // Interate over first array and check it's preffix there exist in hash map and return max of it
    int longestCommonPrefix_Better(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();

        unordered_set<string> pref;

        for (auto &num : arr2)
        {
            string b = to_string(num);

            for (int i = 0; i < b.length(); i++)
            {
                pref.insert(b.substr(0, i + 1));
            }
        }

        int ans = 0;

        for(auto &num : arr1){
            string a = to_string(num);

            for (int i = 0; i < a.length(); i++)
            {
                if(pref.count(a.substr(0, i + 1))){
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};

int main()
{

    cout << endl;
    return 0;
}