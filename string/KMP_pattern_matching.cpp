// Knuth-Morris-Pratt KMP String Matching Algorithm

#include <iostream>

using namespace std;

vector<int> buildLPS(string s) // longest prefix suffix
{
    int n = s.length();
    vector<int> lps(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            string s1 = s.substr(0, k);
            string s2 = s.substr(i - k + 1, k);

            cout << s1 << " " << s2;

            if (s1 == s2)
            {
                cout << "  MATCH  ";
                lps[i + 1] = k;
            }

            cout << endl;
        }
    }

    return lps;
}

bool kmpSearch(string text, string pattern)
{
    vector<int> lps = buildLPS(pattern);

    int n = text.length();
    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            j++;
        }
        else
        {
            while (j > 0 && text[i] != pattern[j])
            {
                j = lps[j];
            }
        }

        if (j == pattern.length())
        {
            return true;
        }

        i++;
    }

    cout << endl;

    return false;
}

int main()
{

    string hey = "ababdqwbfuiivijsndabcdabeabf";
    string needle = "ababd";       // lps = [0, 0, 0, 1, 2, 0]
    string needle2 = "abcdabeabf"; // lps = [0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 0]

    cout << kmpSearch(hey, needle2) << endl;

    return 0;
}