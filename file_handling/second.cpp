#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream MyFile("text.txt");
    if (!MyFile)
    {
        cerr << "Failed to open text.txt\n";
        return 1;
    }

    string line;
    while (getline(MyFile, line)){
        cout << line << endl;
    }

    // getline(MyFile, line);
    // getline(MyFile, line);
    // cout << line << '\n';

    MyFile.close();

    return 0;
}