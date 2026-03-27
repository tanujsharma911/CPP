#include <iostream>

using namespace std;

int main()
{
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++)
    {
        string word;
        cin >> word;

        int length = word.length();

        if (length > 10)
        {
            cout << word[0] << length - 2 << word[length - 1] << endl;
        }
        else
            cout << word << endl;
    }

    return 0;
}

/* 4 word localization internationalization pneumonoultramicroscopicsilicovolcanoconiosis
 */