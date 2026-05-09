/*

We have two parts of array: sorted and un-sorted

Initially we select first element sorted part and other un-sorted part

every iteration we select smallest element from unsorted and swap it with last element of sorted part.

*/

#include <iostream>

using namespace std;

void selectionSort(vector<int>& nums){
    int n = nums.size();

    int soted = 0;

    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(nums[j] < nums[mini]){
                mini = j;
            }
        }
        swap(nums[i], nums[mini]);
    }
}

int main() {
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    // Print array before sorting
    cout << "Before selection sort: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    selectionSort(nums);

    // Print array after sorting
    cout << "After selection sort: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
    return 0;
}