#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> firstHalf, vector<int> secondHalf)
{
    vector<int> temp = {};
    int i = 0;
    int j = 0;

    while (i < firstHalf.size() && j < secondHalf.size())
    {
        if (firstHalf[i] <= secondHalf[j])
        {
            temp.push_back(firstHalf[i]);
            i++;
        }
        else
        {
            temp.push_back(secondHalf[j]);
            j++;
        }
    }
    while (i < firstHalf.size())
    {
        temp.push_back(firstHalf[i]);
        i++;
    }
    while (j < secondHalf.size())
    {
        temp.push_back(secondHalf[j]);
        j++;
    }

    return temp;
}
vector<int> mergeSort(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums;

    int mid = nums.size() / 2;

    vector<int> firstHalf(nums.begin(), nums.begin() + mid);
    vector<int> secondHalf(nums.begin() + mid, nums.end());

    firstHalf = mergeSort(firstHalf);
    secondHalf = mergeSort(secondHalf);

    vector<int> ans = merge(firstHalf, secondHalf);
    return ans;
}

int main()
{
    vector<int> arr = {
        54, 32, 78, 12, 45, 90};

    arr = mergeSort(arr);

    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}
