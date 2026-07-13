/*

126. Word Ladder II

A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

- Every adjacent pair of words differs by a single letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
- sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the
shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

*/

#include <iostream>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution
{
public:
   unordered_map<string, unordered_set<string>> predecessors;
   vector<vector<string>> result;

   void build(string word, vector<string> path)
   {
      if (!predecessors[word].size())
      {
         reverse(path.begin(), path.end());
         result.push_back(path);
         return;
      }

      for (string predecessor : predecessors[word])
      {
         path.push_back(predecessor);
         build(predecessor, path);
         path.pop_back();
      }
   }

   vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
   {
      unordered_set<string> wordSet(wordList.begin(), wordList.end());

      if (!wordSet.count(endWord))
      {
         return {};
      }

      wordSet.erase(beginWord);

      queue<string> q;
      q.push(beginWord);

      int currStep = 0;
      bool foundPath = false;
      unordered_map<string, int> distance;
      distance[beginWord] = 0;

      while (!q.empty())
      {
         currStep++;
         int currLevelSize = q.size();

         for (int i = 0; i < currLevelSize; i++)
         {
            string currWord = q.front();
            q.pop();

            for (int charIndex = 0; charIndex < currWord.length(); charIndex++)
            {
               char originalChar = currWord[charIndex];
               string transformedWord = currWord;

               for (char newChar = 'a'; newChar <= 'z'; newChar++)
               {
                  transformedWord[charIndex] = newChar;

                  if (distance.count(transformedWord) && distance[transformedWord] == currStep + 1)
                  {
                     predecessors[transformedWord].insert(currWord);
                  }

                  if (!wordSet.count(transformedWord))
                     continue;

                  predecessors[transformedWord].insert(currWord);

                  if (transformedWord == endWord)
                  {
                     foundPath = true;
                  }

                  q.push(transformedWord);
                  wordSet.erase(transformedWord);
                  distance[transformedWord] = currStep + 1;
               }
            }
         }

         if (foundPath)
            break;
      }

      if (predecessors[endWord].size() > 0)
      {
         build(endWord, {endWord});
      }

      return result;
   }
};

int main()
{

   cout << endl;
   return 0;
}