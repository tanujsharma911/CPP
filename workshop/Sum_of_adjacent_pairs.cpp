#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int prev = -1;

    while (a != -1)
    {
        scanf("%d", &a);

        if (prev != -1 && a != -1)
        {
            cout << prev + a << " ";
        }
        
        prev = a;
    }

    return 0;
}