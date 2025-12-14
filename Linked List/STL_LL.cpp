#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    for (int val : ll)
    {
        cout << val << " ";
    }
    

    return 0;
}