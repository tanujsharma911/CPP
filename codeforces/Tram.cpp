#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int curr = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        int leave, enter;
        cin >> leave >> enter;

        curr = curr - leave;
        curr = curr + enter;
        
        maxCount = max(curr, maxCount);
    }

    cout << maxCount << endl;

    return 0;
}