/*

Triplets with Sum in Range

Given an array arr[]  and a range from l to r, the task is to count the number
of triplets having a sum in the range [l, r].

Examples :

Input: arr = [8, 3, 5, 2], l = 7, r = 11
Output: 1
Explanation: There is only one triplet [2, 3, 5] having sum 10 in range [7, 11].

Input: arr = [5, 1, 4, 3, 2], l = 2, r = 7
Output: 2
Explanation: There are two triplets having sum in range, [1,4,2] and [1,3,2].

*/

#include <iostream>

using namespace std;

class Solution
{
public:
  int atMost(int x, vector<int> &arr)
  {
    int n = arr.size();

    int i = 0, count = 0;

    for (int i = 0; i < n - 2; i++)
    {
      int left = i + 1, right = n - 1;

      while (left < right)
      {
        int sum = arr[i] + arr[left] + arr[right];

        if (sum <= x)
        {
          count += right - left;
          left++;
        }
        else
        {
          right--;
        }
      }
    }

    return count;
  }
  int countTriplets(vector<int> arr, int l, int r)
  {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    return atMost(r, arr) - atMost(l - 1, arr);
  }
};

int main()
{

  cout << endl;
  return 0;
}