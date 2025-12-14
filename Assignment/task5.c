// Author: Tanuj Sharma
// Section: B

// just change the value of string(line no. 19) to check palindrome, no limit for string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size = 3;
char *Stack = NULL;
int top = -1;

void push(char a);
char peak();
void pop();

int main() {
    char string[] = "mam";
    int palindrome = 1;
    Stack = (char*) malloc(2 * sizeof(char));
    
    for (int i = 0; i < strlen(string); i++)
    {
        push(string[i]);
    }
    for (int i = 0; i < strlen(string); i++)
    {
        if(string[i] == peak()){
            pop();
        }
        else{
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
    {
        printf("Palindrome");
    }
    else{
        printf("Not a Palindrome");
    }
    
    

    // printf("%c", peak());

    free(Stack);
    return 0;
}

void push(char a){
    if(top + 1 < size){
        top++;
        Stack[top] = a;
    }
    else{
        Stack = (char*) realloc(Stack, 2 * size * sizeof(char));
        size = 2 * size * sizeof(char);
        top++;
        Stack[top] = a;
    }
}
char peak(){
    if(top > -1){
        return Stack[top];
    }
    else{
        printf("\nerror: stack is empty");
        return '0';
    }
}
void pop(){
    if(top > -1){
        top--;
    }
    else{
        printf("error: stack is empty");
    }
}