#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

void Vector()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};

    // vector<int>::iterator ite;

    for (auto ite = vec.begin(); ite < vec.end(); ite++)
    {
        cout << *(ite) << " ";
    }
}
void List()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    for (list<int>::iterator i = l.begin(); i != l.end(); i++)
    {
        cout << &(*(i)) << " ";
    }
}
void Pair()
{
    vector<pair<int, int>> p{{1, 2}, {2, 3}, {3, 4}};

    for (auto i : p)
    {
        cout << i.first << " " << i.second << endl;
    }
}
void Stack(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    for (int i = 0; i < 3; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    
}

int main()
{
    // Vector();
    // List();
    // Pair();
    Stack();

    return 0;
}