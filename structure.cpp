#include <iostream>

using namespace std;

typedef struct {
    int roll;
    int id;
    char name[20];
} Students;

int main() {
    Students s1;

    cout << sizeof(s1);

    return 0;
}