// 417. Pacific Atlantic Water Flow

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& heights, set<pair<int, int>>& ocean){
        int rows = heights.size();
        int cols = heights[0].size();

        ocean.insert({r, c});

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols){
                if(!ocean.count({new_r, new_c}) && heights[new_r][new_c] >= heights[r][c]){
                    dfs(new_r, new_c, heights, ocean);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        set<pair<int, int>> pac;
        set<pair<int, int>> alt;

        for(int c = 0; c < cols; c++){
            if(!pac.count({0, c}))
                dfs(0, c, heights, pac);

            if(!alt.count({rows - 1, c}))
                dfs(rows - 1, c, heights, alt);
        }
        for(int r = 0; r < rows; r++){
            if(!pac.count({r, 0}))
                dfs(r, 0, heights, pac);

            if(!alt.count({r, cols - 1}))
                dfs(r, cols - 1, heights, alt);
        }

        vector<vector<int>> ans;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pac.count({r, c}) && alt.count({r, c})){
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};

int main() {
    

    cout << endl;
    return 0;
}