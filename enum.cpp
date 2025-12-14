#include <iostream>
#include <functional>

using namespace std;

enum Week
{
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
    sun
};

void b(function<void()> a)
{
    a();
}

int main()
{
    // enum Week day = su;

    // switch (day)
    // {
    // case 0:
    //     cout << "Mon";
    //     break;

    // case 1:
    //     cout << "Tue";
    //     break;

    // case 2:
    //     cout << "Wed";
    //     break;

    // case 3:
    //     cout << "Thu";
    //     break;

    // case 4:
    //     cout << "Fri";
    //     break;

    // case 5:
    //     cout << "Sat";
    //     break;

    // case 6:
    //     cout << "Sun";
    //     break;
    // }

    auto a = [](int x)
    {
        cout << "hello " << x;
    };

    b(a);

    return 0;
}