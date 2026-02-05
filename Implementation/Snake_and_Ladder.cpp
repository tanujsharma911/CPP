/*
 * Leetcode: 909
 * Return minimum steps to reach n * n square in Snake and Ladder game, Starting from
 * bottom left square
 * 
 * Given n * n matrix,
 *      -1  ->  Here is no starting point of snake or ladder
 *      other ->  The ladder or snake ending at
 * 
 * Example 1:
 * {-1, -1, -1, -1, -1, -1},
   {-1, -1, -1, -1, -1, -1},
   {-1, -1, -1, -1, -1, -1},
   {-1, 35, -1, -1, 13, -1},
   {-1, -1, -1, -1, -1, -1},
   {-1, 15, -1, -1, -1, -1}
 * 
 */

#include <iostream>
using namespace std;

pair<int, int> getCoord(int pos, int n){
    pos--;

    int col = pos % n;
    int row = pos / n;

    bool goingRight = row % 2 == 0;

    if(!goingRight){
        col = n - col - 1;
    }

    return {row, col};
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board[0].size();

    reverse(board.begin(), board.end());

    vector<int> vis(n * n + 1, 0);

    queue<pair<int, int>> q;
    q.push({ 1, 0 }); // {label, turns}

    while(!q.empty()){
        int label = q.front().first;
        int turns = q.front().second;
        q.pop();

        if(label == n * n){
            return turns;
        }

        for(int i = 1; i <= 6; i++){
            int next = label + i;
            if(next > n * n) break;

            auto [r, c] = getCoord(next, n);
            int landingAt = board[r][c] == -1 ? next : board[r][c];
            
            if(!vis[landingAt]){

                q.push({landingAt, turns + 1});

                vis[landingAt] = 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    // vector<vector<int>> board = {
    //     {-1, -1},
    //     {-1, 3}
    // };

    cout << snakesAndLadders(board);


    cout << endl;
    return 0;
}
