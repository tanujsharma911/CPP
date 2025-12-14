#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newNode, *tail;

void push_back(int data);
void pop_back();
void print();

int main()
{
    head = NULL;
    tail = NULL;

    push_back(5);
    // push_back(6);
    print();
    pop_back();
    print();

    return 0;
}

void push_back(int data)
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pop_back()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("NULL\n");
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = NULL;
    free(tail);

    tail = temp;
}

void print()
{
    // Print whole linkedlist
    // printf("%p  ", head);
    if (head == NULL)
    {
        printf("Head -> NULL\n");
        return;
    }

    struct node *temp = head;
    printf("HEAD -> ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}