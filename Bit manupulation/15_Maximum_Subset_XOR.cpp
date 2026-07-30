/*

Maximum Subset XOR

Given an array arr[], choose any subset of elements (possibly all elements) such
that the XOR of the chosen elements is maximized.

*/

#include <iostream>
using namespace std;

// Brute force
class Solution {
public:
  int maxSubsetXOR(vector<int> &arr) {
    int n = arr.size();

    int maxXOR = 0;

    int subsets = 1 << n;

    for (int i = 0; i < subsets; i++) {
      int currXOR = 0;

      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          currXOR = currXOR ^ arr[j];
        }
      }

      maxXOR = max(maxXOR, currXOR);
    }

    return maxXOR;
  }
};

// Using Gaussian elimination
class Solution2 {
public:
  int find_largest_element_with_bit_set(int bit, int st, vector<int> &arr) {
    int n = arr.size();

    int maxElement = st;

    for (int i = st; i < n; i++) {
      if (arr[i] & (1 << bit) && arr[i] > arr[maxElement]) {
        maxElement = i;
      }
    }

    return maxElement;
  }
  int maxSubsetXOR(vector<int> arr) {
    int n = arr.size();

    int index = 0;

    // MSB to LSB
    for (int bit = 31; bit >= 0 && index < n; bit--) { // O(32)
      int largest_element_with_bit_set =
          find_largest_element_with_bit_set(bit, index, arr); // O(n)

      // If no element has the current bit set, continue
      if ((arr[largest_element_with_bit_set] & (1 << bit)) == 0) {
        continue;
      }

      // Bring largest element with bit set to the current index
      swap(arr[largest_element_with_bit_set], arr[index]);

      // Eliminate the bit from all other numbers
      for (int i = 0; i < n; i++) { // O(n)
        if (arr[i] & (1 << bit) && i != index) {
          arr[i] = arr[i] ^ arr[index];
        }
      }

      index++;
    }

    int maxXOR = 0;

    for (auto x : arr) {
      maxXOR = maxXOR ^ x;
    }

    return maxXOR;
  }
};

int main() {

  cout << endl;
  return 0;
}
