/*
Count Inversions (Medium)

Given an array of integers arr[]. You have to find the Inversion Count of the array.
Note : Inversion count is the number of pairs of elements (i, j)
such that i < j and arr[i] > arr[j].

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
*/

#include <algorithm>
#include <iostream>
using namespace std;

int cnt = 0;

void merge(int i, int mid, int j, vector<int>& arr){
    vector<int> temp;

    int left = i, right = mid + 1;

    while(left <= mid && right <= j){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            cnt += mid - left + 1;
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= j){
        temp.push_back(arr[right]);
        right++;
    }

    for(int k = 0; k < temp.size(); k++){
        arr[i + k] = temp[k];
    }
}

void inversionCount(int i, int j, vector<int> &arr) {
    if(i >= j) return;

    int mid = (i + j) / 2;

    inversionCount(i, mid, arr);
    inversionCount(mid + 1, j, arr);

    merge(i, mid, j, arr);
}

int main()
{
    vector<int> arr = {10, 10, 10};
    inversionCount(0, arr.size() - 1, arr);

    cout << "Number of inversions: " << cnt << endl;

    for(auto it: arr) cout << it << " ";


    cout << endl;
    return 0;
}