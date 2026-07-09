/*

Count Pairs Divisible By K

Given an array arr[] and positive integer k, count total number of
pairs in the array whose sum is divisible by k.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int countKdivPairs(vector<int> &arr, int k)
   {
      int n = arr.size();

      unordered_map<int, int> remainder_freq;

      int totalPairs = 0;

      for (auto num : arr)
      {

         if (remainder_freq.count((k - (num % k)) % k)) // NOTE: doing again modulo of k - rem becoz rem can be zero and k will never exist in freq map
         {
            totalPairs += remainder_freq[(k - (num % k)) % k];
         }

         remainder_freq[num % k]++;
      }

      return totalPairs;
   }
};

/*

nums[i] % 2 + nums[j] % 2 == k

*/

int main()
{

   cout << endl;
   return 0;
}