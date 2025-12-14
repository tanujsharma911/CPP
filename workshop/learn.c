#include <stdio.h>

int display(int (*ptr)(int, int), int, int);
int sum(int, int);
int sub(int, int);

int main()
{

    printf("%p", display);

    return 0;
}

int display(int (*ptr)(int, int), int a, int b)
{
    return ptr(a, b);
}
int sum(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}