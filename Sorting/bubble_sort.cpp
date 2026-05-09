/*

Came from back of the array n - 1

and inner loop come from 0, And bigger element is pushed near the back of the array

*/

#include <iostream>

using namespace std;

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                didSwap = true;
            }
        }

        if (!didSwap)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    // Print array before sorting
    cout << "Before selection sort: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    bubbleSort(nums);

    // Print array after sorting
    cout << "After selection sort: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
    return 0;
}