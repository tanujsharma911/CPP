/*

start placing elements from index 1

left child is on i * 2
right child is on i * 2 + 1

# Heapify:
   leaf nodes are from index n / 2 + 1 to n index
   If we start Heapification, we can skip index n / 2 + 1 to n index
   and start from n / 2 to 0 index

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Heap
{
public:
   vector<int> arr;
   int size;

   Heap(int n)
   {
      this->size = 0;
      this->arr.resize(n + 1, 0);
   }

   bool insert(int val)
   {
      if (size + 1 >= arr.size())
      {
         return false;
      }

      size++;

      int index = size;
      arr[index] = val;

      while (index > 1)
      {
         int parent = index / 2;

         if (arr[parent] < arr[index])
         {
            swap(arr[parent], arr[index]);
            index = parent;
         }
         else
         {
            return true;
         }
      }

      return true;
   }

   void print()
   {
      for (int i = 1; i <= size; i++)
      {
         cout << arr[i] << " ";
      }
      cout << endl;
   }

   bool remove()
   {
      if (size == 0)
      {
         return false;
      }

      arr[1] = arr[size];
      size--;

      int i = 1;

      while (i <= size)
      {
         int left = i * 2;
         int right = i * 2 + 1;
         int largest = i;

         if(left <= size && arr[largest] < arr[left]){
            largest = left;
         }
         if(right <= size && arr[largest] < arr[right]){
            largest = right;
         }

         if(largest != i){
            swap(arr[largest], arr[i]);
            i = largest;
         }
         else {
            break;
         }
      }

      return true;
   }
};

void heapify(int arr[], int n, int i)
{
   int largest = i;
   int left = 2 * i;
   int right = 2 * i + 1;

   if (left <= n && arr[left] > arr[largest])
   {
      largest = left;
   }

   if (right <= n && arr[right] > arr[largest])
   {
      largest = right;
   }

   if (largest != i)
   {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
   }
}

int main()
{
   // Heap h(5);

   // h.insert(50);
   // h.insert(55);
   // h.insert(53);
   // h.insert(52);
   // h.insert(54);

   // h.print();
   // h.remove();
   // h.print();

   int arr[6] = {-1, 54, 53, 55, 52, 50};

   for (int i = 6 / 2; i >= 1; i--)
   {
      heapify(arr, 5, i);
   }

   for (int i = 1; i <= 5; i++)
   {
      cout << arr[i] << " ";
   }

   cout << endl;
   return 0;
}