#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Create object
    ofstream *fout = new ofstream();

    // Open file
    fout->open("text.txt");

    cout << fout->is_open() << endl; // if file is open

    if (fout->bad())
    {
        cout << "Stream is corrupted (fatal error)" << endl;
    }
    else if (fout->fail())
    {
        cout << "Fail to write" << endl;
    }
    else if (fout->good())
    {
        cout << "Write succussfull" << endl;
    }

    // Write in file
    *fout << "Hello file";

    // Close file
    fout->close();

    return 0;
}