#include <iostream>

using namespace std;

int count(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;

    return 2 * count(n - 1) + 1;
}

int i = 1;
void displaySteps(int n, string s, string h, string d)
{
    if (n <= 1)
    {
        cout << i << ". Move 1 from " << s << " to " << d << endl;
        i++;
        return;
    }

    displaySteps(n - 1, s, d, h);
    cout << i << ". Move " << n << " from " << s << " to " << d << endl;
    i++;
    displaySteps(n - 1, h, s, d);
}

int main()
{
    int n = 4;
    cout << "Count: " << count(n) << endl;
    cout << "Steps: \n";
    displaySteps(n, "S", "H", "D");

    return 0;
}