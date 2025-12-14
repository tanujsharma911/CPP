
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        prev = next = NULL;
    }
};

class DList
{
public:
    Node *head;
    Node *tail;

    DList(){
        head = tail = nullptr;
    }

    void push_front(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(int data)
    {
        Node *newNode = new Node(data);

        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void printAll(){
        Node *temp = head;

        cout << "\nhead -> ";
        while(temp != NULL){
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void pop_front(){
        if(head == NULL){
            cout << "No elements found" << endl;
            return;
        }
        else if (head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        del->next = del->prev = NULL;
        delete del;
        del = NULL;
    }
    void pop_back(){
        if(tail == NULL){
            cout << "No element found" << endl;
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        tail->prev->next = NULL;
        Node *del = tail;
        tail = tail->prev;
        del->prev = NULL;
        delete del;
        del = NULL;

        // tail->prev = NULL;
    }

    
};

class Queue {
public:
    Node *first;
    Node *last;

    Queue(){
        first = nullptr;
        last = nullptr;
    }
    void print(){
        Node *temp = first;

        cout << "Head -> ";
        while(temp != nullptr){
            cout << temp->data << " <=> ";

            temp = temp->next;
        }
        cout << "NULL";
    }
    void push(int data){
        Node *newNode = new Node(data);

        if (first == NULL)
        {
            first = last = newNode;
            return;
        }
        last->next = newNode;
        newNode->prev = last;
        last = last->next;
    }
    void pop(){
        if (first == nullptr)
        {
            return;
        }
        else if(last == first){
            delete first;
            first = last = nullptr;
            return;
        }
        
        Node *del = first;

        first = first->next;
        first->prev = nullptr;

        delete del;
    }
};

int main()
{
    Queue q1;

    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);
    q1.print();

    return 0;
}