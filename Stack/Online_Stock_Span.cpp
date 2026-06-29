/*
901. Online Stock Span (Medium)

Design an algorithm that collects daily price quotes for some stock and returns
the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive
days (starting from that day and going backward) for which the stock price was
less than or equal to the price of that day.

Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
*/

#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class StockSpanner {
public:
  stack<pair<int, int>> s;
  int index = -1;

  StockSpanner() {}

  int next(int price) {
    index++;
    while (!s.empty() && s.top().second <= price) {
      s.pop();
    }

    if (s.empty()) {
      s.push({index, price});
      return index + 1;
    }

    int span = index - s.top().first;

    s.push({index, price});

    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {

  cout << endl;
  return 0;
}
