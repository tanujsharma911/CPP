/*

Allocate Minimum Pages

The objective is to minimize the maximum number of pages assigned to any student.

books[i] means, Number of pages in i-th book
students means, Number of students

*/

#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool canBeAllocate(int maxPages, vector<int> &pages, int students)
    {
        int n = pages.size();

        int pagesGiven = 0;
        int studentsAllocated = 1;

        for (int i = 0; i < n; i++)
        {
            if (pages[i] > maxPages)
                return false;

            if (pagesGiven + pages[i] <= maxPages)
            {
                pagesGiven += pages[i];
            }
            else
            {
                studentsAllocated++;
                pagesGiven = pages[i];
            }
        }

        return studentsAllocated <= students;
    }
    int findPages(vector<int> &pages, int students)
    {
        int n = pages.size();

        if (students > n)
            return -1; // Books are less than students

        int left = 0, right = accumulate(pages.begin(), pages.end(), 0);

        int minMaxPages = -1;

        while (left <= right)
        {
            int maxPages = left + (right - left) / 2;

            if (canBeAllocate(maxPages, pages, students))
            {
                minMaxPages = maxPages;
                right = maxPages - 1;
            }
            else
            {
                left = maxPages + 1;
            }
        }

        return minMaxPages;
    }
};

int main()
{

    cout << endl;
    return 0;
}