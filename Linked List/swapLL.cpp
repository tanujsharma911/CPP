#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LL
{
public:
    Node *head, *tail;

    LL()
    {
        head = NULL;
        tail = NULL;
    }
    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
    void push_back(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main()
{
    LL ll;

    return 0;
}