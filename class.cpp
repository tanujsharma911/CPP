/*Write a C++ program to demonstrate the use of a parameterized constructor in a class
Rectangle. The constructor should accept the length and breadth of the rectangle,
and the class should include a function to calculate and display the area.*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // Parameterized constructor
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    // Function to calculate area
    void displayArea()
    {
        int area = length * breadth;
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main()
{
    // Creating object using parameterized constructor
    Rectangle rect1(10, 5);
    Rectangle rect2(11, 6);
    Rectangle rect3(12, 7);

    // Display area
    rect1.displayArea();
    rect2.displayArea();
    rect3.displayArea();

    return 0;
}
