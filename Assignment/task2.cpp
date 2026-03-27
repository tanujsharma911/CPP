// Author: Tanuj Sharma
// Section: B

#include <iostream>

using namespace std;

const int SIZE = 3;
int Stack[SIZE];

int top1 = -1;   // Stack 1 pointer to top (Left Stack)
int top2 = SIZE; // Stack 2 pointer to top (Right stack)

int pushS1(int a);
int peakS1();
int popS1();
int pushS2(int a);
int peakS2();
int popS2();

int main()
{
    pushS1(1);
    pushS2(3);
    pushS2(2);
    pushS2(4);
    cout << peakS1() << endl;
    cout << peakS2() << endl;

    return 0;
}

int pushS1(int a)
{
    if (top1 + 1 < top2)
    {
        top1++;
        Stack[top1] = a;
    }
    else
    {
        cout << "error: Stack full can't add " << a << endl;
        return 0; // unsuccussfull
    }

    return 1;
}
int peakS1()
{
    if (top1 > -1 && top1 < top2)
    {
        return Stack[top1];
    }
    return 0;
}
int popS1()
{
    if (top1 > -1)
    {
        top1--;
    }
    else
    {
        cout << "error: Stack is empty" << endl;
        return 0; // unsuccussfull
    }

    return 1;
}

int pushS2(int a)
{
    if (top2 - 1 > top1)
    {
        top2--;
        Stack[top2] = a;
    }
    else
    {
        cout << "error: Stack full can't add "<< a << endl;
        return 0;  // unsuccessfull
    }
    return 1;
}
int peakS2()
{

    if (top2 > top1 && top2 < SIZE)
    {
        return Stack[top2];
    }
    return 0;
}
int popS2()
{
    if (top2 < SIZE)
    {
        top2++;
    }
    else
    {
        cout << "error: Stack is empty" << endl;
        return 0; // unsuccussfull
    }

    return 1;
}