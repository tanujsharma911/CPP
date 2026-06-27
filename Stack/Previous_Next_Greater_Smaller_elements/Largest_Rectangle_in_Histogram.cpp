/*
84. Largest Rectangle in Histogram
Link:- https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given an array of integers heights representing the histogram's bar height where
the width of each bar is 1, return the area of the largest rectangle in the histogram.

revised: 1

*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findPSE(vector<int>& heights){
        int n = heights.size();

        stack<int> pse;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int el = heights[i];

            while(!pse.empty() && heights[pse.top()] >= el){
                pse.pop();
            }

            if(pse.empty()){
                ans[i] = -1;
            }
            else {
                ans[i] = pse.top();
            }

            pse.push(i);
        }

        return ans;
    }
    vector<int> findNSE(vector<int>& heights){
        int n = heights.size();

        stack<int> nse;
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; i--){
            int el = heights[i];

            while(!nse.empty() && heights[nse.top()] >= el){
                nse.pop();
            }

            if(nse.empty()){
                ans[i] = n;
            }
            else {
                ans[i] = nse.top();
            }

            nse.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int largestArea = 0;

        for(int i = 0; i < n ; i++){
            int breath = nse[i] - pse[i] - 1;
            int height = heights[i];

            largestArea = max(largestArea, breath * height);
        }

        return largestArea;
    }
};

int main()
{

    return 0;
}
