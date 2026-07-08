// 399. Evaluate Division

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> m;

    double getValue(string node_c, string node_d){
        if(!m.count(node_c) || !m.count(node_d)){
            return -1.0;
        }

        queue<pair<string, double>> q;
        set<string> vis;

        q.push({node_c, 1});
        vis.insert(node_c);

        while(!q.empty()){
            string node_curr = q.front().first;
            double node_dis = q.front().second;
            q.pop();

            if(node_curr == node_d){
                return node_dis;
            }

            for(auto& neighbour : m[node_curr]){
                if(vis.count(neighbour.first)) continue;

                q.push({neighbour.first, neighbour.second * node_dis});
                vis.insert(neighbour.first);
            }
        }

        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        for(int i = 0; i < n; i++){
            string node_a = equations[i][0];
            string node_b = equations[i][1];
            double value = values[i];

            m[node_a].push_back({node_b, value});
            m[node_b].push_back({node_a, (1 / value)});
        }

        vector<double> ans;

        for(int i = 0; i < queries.size(); i++){
            string node_c = queries[i][0];
            string node_d = queries[i][1];

            ans.push_back(getValue(node_c, node_d));
        }

        return ans;
    }
};

int main() {
    

    cout << endl;
    return 0;
}