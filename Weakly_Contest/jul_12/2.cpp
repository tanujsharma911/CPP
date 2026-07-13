#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int minimumCost(vector<int> &nums, int k)
   {
      int n = nums.size();
      int mod = 1e9 + 7;

      long long cost = 0;
      int resources = k;
      long long fillCost = 1;

      for (int i = 0; i < n; i++)
      {
         if (nums[i] <= resources)
         {
            resources -= nums[i];
         }
         else
         {
            int deficit = nums[i] - resources;
            int x = (deficit + k - 1) / k;

            cost = (cost + (fillCost * x) + ((x - 1) * x) / 2) % mod;
            resources += k * x;
            fillCost += x;

            resources -= nums[i];
         }
      }

      return cost;
   }
};

int main()
{
   Solution s;

   vector<int> arr = {1, 1, 7, 14};

   cout << s.minimumCost(arr, 4);

   cout << endl;
   return 0;
}