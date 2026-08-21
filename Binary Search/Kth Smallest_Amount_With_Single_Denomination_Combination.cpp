/*

3116. Kth Smallest Amount With Single Denomination Combination

You are given an integer array coins representing coins of different denominations and an
integer k.

You have an infinite number of coins of each denomination. However, you are not allowed
to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

Example 1:

Input: coins = [3,6,9], k = 3

Output: 9

Explanation: The given coins can make the following amounts:
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
All of the coins combined produce: 3, 6, 9, 12, 15, etc.

Example 2:

Input: coins = [5,2], k = 7

Output: 12

Explanation: The given coins can make the following amounts:
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.


*/

#include <iostream>

using namespace std;

class Solution
{
public:
  long long gcd(long long a, long long b)
  {
    if (b == 0)
      return a;

    return gcd(b, a % b);
  }
  long long lcm(long long a, long long b)
  {
    return (a * b) / gcd(a, b);
  }
  long long pos(long long x, vector<int> &coins)
  {
    int n = coins.size();

    long long total = 0;

    for (int mask = 1; mask < (1 << n); mask++)
    {
      int bits = 0;
      long long subset_lcm = 1;

      for (int i = 0; i < n; i++)
      {
        if (mask & (1 << i))
        {
          bits++;
          subset_lcm = lcm(subset_lcm, coins[i]);
        }
      }

      long long term = x / subset_lcm;

      if (bits % 2 == 0)
      {
        total -= term;
      }
      else
      {
        total += term;
      }
    }

    return total;
  }
  long long findKthSmallest(vector<int> &coins, int k)
  {
    int n = coins.size();

    long long l = 1, r = 50 * pow(10, 9) + 1, ans = 1;

    while (l < r)
    {
      long long x = l + (r - l) / 2;

      if (pos(x, coins) >= k)
      {
        ans = x;
        r = x;
      }
      else
      {
        l = x + 1;
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