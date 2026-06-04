// 3751. Total Waviness of Numbers in Range I

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int noOfWaviness(int i, string num)
    {
        int n = num.length();

        if (n < 3)
        {
            return 0;
        }
        if (i == n - 1)
        {
            return 0;
        }

        int left_digit = num[i - 1] - '0';
        int curr_digit = num[i] - '0';
        int right_digit = num[i + 1] - '0';

        if (left_digit < curr_digit && curr_digit > right_digit)
        {
            return 1 + noOfWaviness(i + 1, num);
        }
        else if (left_digit > curr_digit && curr_digit < right_digit)
        {
            return 1 + noOfWaviness(i + 1, num);
        }
        else
        {
            return noOfWaviness(i + 1, num);
        }
    }
    int totalWaviness(int num1, int num2)
    {
        int totalWaviness = 0;

        for (int num = max(100, num1); num <= num2; num++)
        {
            string x = to_string(num);
            totalWaviness += noOfWaviness(1, x);
        }

        return totalWaviness;
    }
};

int main()
{

    cout << endl;
    return 0;
}