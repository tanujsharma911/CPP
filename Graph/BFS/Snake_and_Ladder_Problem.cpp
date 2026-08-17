/*

Snake and Ladder Problem

Given an integer n such that there is n × n Snakes and Ladders board with cells
 numbered from 1 to n*n, find the minimum number of dice throws required to reach
 cell n*n starting from cell 1. Given two arrays of even lengths:

lad[], where each pair (lad[2*i], lad[2*i + 1]) represents the start and end of a ladder.
sn[], where each pair (sn[2*i], sn[2*i + 1]) represents the start and end of a snake.
If you land on the start cell of a snake or ladder, you must immediately move to its
corresponding end cell.

You have complete control over the outcome of each dice throw i.e., in a single move,
you can move forward by any number of cells from 1 to 6.

If it is impossible to reach cell n*n, return -1.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int minThrows(int n, vector<int> &lad, vector<int> &sn)
    {
        unordered_map<int, int> ladder;
        unordered_map<int, int> snake;

        for (int i = 0; i < lad.size(); i += 2)
        {
            ladder[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2)
        {
            snake[sn[i]] = sn[i + 1];
        }

        // auto comp = [](const pair<int, int>& a, const pair<int, int>& b){
        //     if(a.first != b.first){
        //         return a.first > b.first;
        //     }
        //     return a.second < b.second;
        // };

        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp); // (steps, cell)

        queue<pair<int, int>> pq; // (steps, cell)
        vector<bool> vis(n * n + 1, false);

        pq.push({0, 1});
        vis[1] = true;

        while (!pq.empty())
        {
            int steps = pq.front().first;
            int pos = pq.front().second;
            pq.pop();

            for (int dice = 1; dice <= 6; dice++)
            {
                int next = pos + dice;

                if (next > n * n)
                    break;

                if (ladder.count(next))
                {
                    next = ladder[next];
                }
                else if (snake.count(next))
                {
                    next = snake[next];
                }

                if (vis[next])
                    continue;

                if (next == n * n)
                {
                    return steps + 1;
                }

                pq.push({steps + 1, next});
                vis[next] = true;
            }
        }

        return -1;
    }
};

int main()
{

    cout << endl;
    return 0;
}