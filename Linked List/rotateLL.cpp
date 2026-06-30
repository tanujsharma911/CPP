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

Node *head, *tail;
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

void display()
{
    int i;

    Node *ptr = head;
    while (ptr != nullptr && i < 50)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;

        i++;
    }
    cout << "NULL\n";
}

int main()
{
    head = tail = nullptr;

    push_back(69);
    push_back(67);

    cout << "1\n";
    display();

    int k = 3;

    int index = 1;
    int size = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        size++;

        temp = temp->next;
    }

    k = k % size;

    cout << "size: " << k << endl;

    if (k == size || k < 1)
    {
        cout << "Not used\n";
        display();
        return 0;
    }

    Node *curr = head;
    Node *second = nullptr;

    while (index < k)
    {
        second = curr->next;
        curr = curr->next;

        index++;
    }
    second = curr->next;
    Node *newHead = second;

    cout << "curr: " << curr->data << endl;
    cout << "next: " << second->data << endl;

    curr->next = NULL;

    while (second->next != nullptr)
    {
        second = second->next;
    }
    second->next = head;

    head = newHead;

    display();

    return 0;
}