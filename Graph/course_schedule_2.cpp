// 210. Course Schedule II

#include <iostream>
#include <vector>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> courses(numCourses); // graph
    vector<int> ans;

    // No pre-requisites
    if(prerequisites.size() == 0){
        for(int i = 0; i < numCourses; i++){
            ans.push_back(i);
        }

        return ans;
    }

    // Construct adjustance matrix
    for(auto& prerequisite : prerequisites){
        int course_a = prerequisite[0];
        int course_b = prerequisite[1];

        courses[course_b].push_back(course_a);
    }
    vector<int> in_degree(numCourses, 0);

    for(int curr_course = 0; curr_course < numCourses; curr_course++){
        for(auto prerequisite : courses[curr_course]){
            in_degree[prerequisite]++;
        }
    }


    queue<int> q;

    // Push 0 in_degree nodes
    for(int i = 0; i < numCourses; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo_sort;

    while(!q.empty()){
        int curr_course = q.front();
        q.pop();

        topo_sort.push_back(curr_course);

        for(auto neighbour: courses[curr_course]){
            in_degree[neighbour]--;

            if(in_degree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(topo_sort.size() != numCourses) return {};

    return topo_sort;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};

    vector<int> ans = findOrder(numCourses, prerequisites);

    for(auto num : ans){
        cout << num << " ";
    }
    

    cout << endl;
    return 0;
}