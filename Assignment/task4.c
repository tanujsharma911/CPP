// Author: Tanuj Sharma
// Section: B

#include <stdio.h>

// Number of elements of Stack
const int StackSize = 10;

// declaring stack
char Stack[StackSize];
int top = -1;

// function prototypes
void push(char a);
int peak();
void pop();
void undo();


int main() {

    // Filling stack with some elements for example
    // Let stack = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    for (int i = 1; i <= StackSize; i++)
    {
        push(i);
    }

    pop();  // Now stack = 1, 2, 3, 4, 5, 6, 7, 8, 9 <-- top
    undo();  // Now stack = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 <-- top

    // Printing elements of stack
    for (int i = 0; i < StackSize; i++)
    {
        printf("%c ", peak());
        pop();
    }

    return 0;
}


void push(char a){  // Add element 'a' at top of stack
    if(top + 1 < StackSize){
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
void undo(){
    if(top < StackSize - 1){
        top++;
    }
    else{
        printf("\nerror: Stack is full");
    }
}