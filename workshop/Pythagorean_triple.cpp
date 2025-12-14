#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
        swap(a, b);
    if (b > c)
        swap(c, b);
    if (a > b)
        swap(a, b);

    if (a * a + b * b == c * c)
    {
        printf("yes");
    }
    else {
        printf("no");
    }

    return 0;
}