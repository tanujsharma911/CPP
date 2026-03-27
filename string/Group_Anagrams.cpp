#include <iostream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();

    vector<vector<int>> strs_freq(n, vector<int>(26, 0));

    for(int i = 0; i < n; i++){
        string word = strs[i];

        for(char c : word){
            strs_freq[i][c - 'a']++;
        }
    }

    unordered_map<string, vector<string>> map;

    for(auto word: strs){
        string key = word;
        sort(key.begin(), key.end());

        if(map.count(key)){
            map[key].push_back(word);
        }
        else {
            map[key] = {word};
        }
    }

    vector<vector<string>> groups;


    for(auto &key_group: map){
        vector<string> group = key_group.second;

        groups.push_back(group);
    }


    return groups;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> groups = groupAnagrams(strs);

    for(auto group : groups){
        for(auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
