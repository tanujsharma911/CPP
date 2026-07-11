/*

127. Word Ladder


A transformation sequence from word beginWord to word endWord using a dictionary
 wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of
words in the shortest transformation sequence from beginWord to endWord, or 0 if no
such sequence exists.

*/

#include <iostream>
#include <numeric>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
   int ladderLength(string beginWord, string endWord, vector<string> &wordList)
   {
      unordered_set<string> words(wordList.begin(), wordList.end());

      queue<string> q;
      q.push(beginWord);

      int steps = 1;

      while (!q.empty())
      {
         steps++;

         int currLevelSize = q.size();
         for (int i = 0; i < currLevelSize; i++)
         {
            string currWord = q.front();
            q.pop();

            for (int charIndex = 0; charIndex < currWord.length(); charIndex++)
            {
               char originalChar = currWord[charIndex];

               for (char newChar = 'a'; newChar <= 'z'; newChar++)
               {
                  currWord[charIndex] = newChar;

                  if (!words.count(currWord))
                  {
                     continue;
                  }

                  if (currWord == endWord)
                     return steps;

                  q.push(currWord);
                  words.erase(currWord);
               }

               currWord[charIndex] = originalChar;
            }
         }
      }

      return 0;
   }
};

int main()
{

   cout << endl;
   return 0;
}