#include <stdio.h>

int arr[6];
int front = -1;
int rear = -1;

int main()
{
    int input = 1;
    int add;
    while (input)
    {
        printf("0: exit \n1: insertion \n2: deletion \n3: display\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\n Enter the element: ");
            scanf("%d", &add);
            if(front == -1)
            {
                front++;
                rear++;
                arr[front] = add;
            }
            else if (rear + 1 < 6)
            {
                rear++;
                arr[rear] = add;
            }
            else{
                printf("stack is full\n");
            }
            break;

        case 2:
            if(front < rear){
                front++;
            }
            break;

        case 3:
            if(front > -1)
                printf("\n Front element: %d\n", arr[front]);
            break;

        default:
            input = 0;
            break;
        }
    }

    return 0;
}