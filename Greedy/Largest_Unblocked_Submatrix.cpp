/*

Largest Unblocked Submatrix

Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r,
c] represents a blocked cell (1-based indexing) in an n × m grid. Each blocked
cell blocks its entire row and column. Find the largest continuous unblocked
area in the grid.

Note: No two blocked cells are in the same row or the same column.

*/

#include <iostream>

using namespace std;

class Solution {
public:
  int largestArea(int n, int m, vector<vector<int>> arr) {
    vector<int> rows = {-1};
    vector<int> cols = {-1};

    for (int i = 0; i < arr.size(); i++) {
      rows.push_back(arr[i][0] - 1);
      cols.push_back(arr[i][1] - 1);
    }

    rows.push_back(n);
    cols.push_back(m);

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    int row_largest_area = 0;

    for (int i = 1; i < rows.size(); i++) {
      if (rows[i] - rows[i - 1] - 1 > row_largest_area) {
        row_largest_area = rows[i] - rows[i - 1] - 1;
      }
    }

    int col_largest_area = 0;

    for (int i = 1; i < cols.size(); i++) {
      if (cols[i] - cols[i - 1] - 1 > col_largest_area) {
        col_largest_area = cols[i] - cols[i - 1] - 1;
      }
    }

    return row_largest_area * col_largest_area;
  }
};

int main() {

  cout << endl;
  return 0;
}