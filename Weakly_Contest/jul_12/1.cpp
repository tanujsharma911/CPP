#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int convertToSeconds(string time)
   {
      int hr = stoi(time.substr(0, 2));
      int min = stoi(time.substr(3, 2));
      int sec = stoi(time.substr(6, 2));

      return (hr * 60 * 60) + (min * 60) + sec;
   }
   int secondsBetweenTimes(string startTime, string endTime)
   {
      int startTimeInSeconds = convertToSeconds(startTime);
      int endTimeInSeconds = convertToSeconds(endTime);

      return endTimeInSeconds - startTimeInSeconds;
   }
};

int main()
{
   Solution s;

   cout << s.secondsBetweenTimes("12:34:56",  "13:00:00");

   cout << endl;
   return 0;
}