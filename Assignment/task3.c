// Author: Tanuj Sharma
// Section: B

#include <stdio.h>

// Number of elements of list
const int ListSize = 10;

// declaring stack
int Stack[ListSize];
int top = -1;

// function prototype
void print(int *arr);
void push(int a);
int peak();
void pop();


int main() {
    int list[ListSize];

    // Getting elements of list from terminal
    printf("Enter %d elements of list:\n", ListSize);
    for(int i = 0; i < ListSize; i++)
    {
        scanf("%d", &list[i]);
    }
    
    // Traverse list and push it in stack
    for(int i = 0; i < ListSize; i++)
    {
        push(list[i]);
    }

    //  Traverse list 
    for(int i = 0; i < ListSize; i++)
    {
        list[i] = peak(); //  replace element of list with top element of stack
        pop();  //  Remove top element of stack
    }
    
    print(list);  //  Print array

    return 0;
}

void print(int *arr){  //  Print array
    for (int i = 0; i < ListSize; i++)
    {
        printf("%d ", arr[i]);
    }
    
}
void push(int a){  // Add element 'a' at top of stack
    if(top + 1 < ListSize){
        top++;
        Stack[top] = a;
    }
    else{
        printf("\nerror: stack is full");
    }
}
int peak(){  //  Get top element of stack
    if(top > -1){
        return Stack[top];
    }
    else{
        printf("\nerror: Stack is empty");
    }
    return 0;
}

void pop(){  // Remove top element of stack
    if (top > -1)
    {
        top--;
    }
    else{
        printf("\nerror: Stack is empty");
    }
}