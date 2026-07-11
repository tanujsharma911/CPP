/*

Min Heap implementation

Implement a class minHeap that supports the following operations:

push(x) – push element x into the heap
pop() – remove the top element from the heap
peek() – return top element from the heap, if empty return -1
size() - return the no of elements in the heap.
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : call push(x)
2: call pop()
3: call peek()
4: call size()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(),
size() operation.

You only need to implement the above four functions.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class minHeap
{
private:
   int arr[1000] = {-1};
   int n = 0;

public:
   void push(int x)
   {
      int index = n + 1;
      n++;

      arr[index] = x;

      while (index > 1)
      {
         int parent = index / 2;

         if (arr[parent] > arr[index])
         {
            swap(arr[parent], arr[index]);
            index = parent;
         }
         else
         {
            break;
         }
      }
   }

   void pop()
   {
      arr[1] = arr[n];
      n--;

      int index = 1;

      while (index < n)
      {
         int left = index * 2;
         int right = index * 2 + 1;
         int largest = index;

         if (left <= n && arr[left] < arr[largest])
         {
            largest = left;
         }

         if (right <= n && arr[right] < arr[largest])
         {
            largest = right;
         }

         if (largest != index)
         {
            swap(arr[index], arr[largest]);
            index = largest;
         }
         else
         {
            break;
         }
      }
   }

   int peek()
   {
      if (n == 0)
         return -1;

      return arr[1];
   }

   int size()
   {
      return n;
   }
};

int main()
{

   cout << endl;
   return 0;
}