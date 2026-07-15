/*

Alien Dictionary

A new alien language uses the English alphabet, but the order of letters is unknown.
You are given a list of words[] from the alien language’s dictionary, where the words
are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based
on the given words. If the order is valid, return a string containing the unique letters
in lexicographically increasing order as per the new language's rules. If there are
multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter
ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position
where they differ, the character in a appears earlier in the alien language than the
corresponding character in b. If all characters in the shorter word match the beginning
of the longer word, the shorter word is considered smaller.

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
   string findOrder(vector<string> &words)
   {
      int n = words.size();

      unordered_map<char, vector<char>> adj;
      unordered_map<char, int> in_degree;

      for (const string &word : words)
      {
         for (char c : word)
         {
            in_degree[c] = 0;
         }
      }

      for (int i = 1; i < n; i++)
      {
         string a = words[i - 1];
         string b = words[i];

         int j = 0;

         while (j < a.length() && j < b.length() && a[j] == b[j])
         {
            j++;
         }

         if (j == b.length() && j < a.length())
            return "";

         if (j == a.length())
            continue;

         adj[a[j]].push_back(b[j]);

         in_degree[b[j]]++;
      }

      queue<char> q;

      for (const auto &[node, degree] : in_degree)
      {
         if (degree == 0)
         {
            q.push(node);
         }
      }

      string dictionary = "";

      while (!q.empty())
      {
         char curr = q.front();
         q.pop();

         dictionary.push_back(curr);

         for (auto neighbour : adj[curr])
         {
            in_degree[neighbour]--;

            if (in_degree[neighbour] == 0)
            {
               q.push(neighbour);
            }
         }
      }

      if (dictionary.length() != in_degree.size())
      {
         return "";
      }

      return dictionary;
   }
};

int main()
{

   cout << endl;
   return 0;
}