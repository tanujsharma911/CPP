#include <stdio.h>

void greet()
{
    static int count = 0;

    count++;
    printf("Hello! This is your %dth visit.\n", count);
}

int main()
{
    greet();
    greet();
    greet();
    return 0;
}