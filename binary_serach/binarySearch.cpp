#include <iostream>

using namespace std;

int main()
{
    vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char target;

    int start = 0, end = letters.size() - 1, mid, ans = -1;

    cout << "Search letter: ";
    cin >> target;

    while (start <= end)
    {
        mid = end - (end - start) / 2;

        if (letters[mid] == target)
        {
            cout << "Found at index: " << mid << endl;
            ans = mid;
            break;
        }
        else if (letters[mid] < target)
        {
            start = mid + 1;
        }
        else if (letters[mid] > target)
        {
            end = mid - 1;
        }
    }

    if (ans == -1)
    {
        cout << "Not found";
    }

    return 0;
}
