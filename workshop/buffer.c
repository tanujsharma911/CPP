#include <stdio.h>
#include <string.h>

int main()
{
    // int i;
    // char c;
    // scanf("%d", &i);
    // printf("read: %d\n", i);

    // printf("Let's check what is in the input buffer:\n");
    // while (scanf("%c", &c) == 1)
    // {
    //     printf("read from input buf: %d\n", c);
    // }

    char name[10] = "1234567890";

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", name[i]);
    }
    

    return 0;
}