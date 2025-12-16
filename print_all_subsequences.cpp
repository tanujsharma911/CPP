#include <iostream>

using namespace std;

template <typename T>

void printSubSequence(vector<T> &arr, int i = 0, vector<T> ss = {})
{
    int n = arr.size();

    if (i >= n)
    {
        cout << "[";
        for (int i = 0; i < ss.size(); i++)
        {
            if (i != ss.size() - 1)
            {
                cout << ss[i] << ", ";
            }
            else
            {
                cout << ss[i] << "] \n";
            }
        }
        return;
    }

    ss.push_back(arr[i]);
    printSubSequence(arr, i + 1, ss);

    ss.pop_back();
    printSubSequence(arr, i + 1, ss);
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    vector<char> s = {'a', 'b', 'c'};

    printSubSequence(s);

    return 0;
}