#include <iostream>

using namespace std;

int main()
{
    vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    vector<char> suit = {'D', 'C', 'S', 'H'};

    string onTable;
    cin >> onTable;

    bool played = false;
    for (int  i = 0; i < 5; i++)
    {
        string hand;
        cin >> hand;

        if(hand[0] == onTable[0]){
            played = true;
            break;
        }
        else if (hand[1] == onTable[1])
        {
            played = true;
            break;
        }
    }
    
    if(!played){
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}