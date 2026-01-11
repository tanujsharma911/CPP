/*
84. Largest Rectangle in Histogram
Link:- https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

revised: 1

*/

#include <iostream>

using namespace std;

int largestRectangleArea(vector<int> heights)
{
    vector<int> nextSmaller(heights.size(), 0);
    stack<int> nextSmallerStack;

    vector<int> prevSmaller(heights.size(), 0);
    stack<int> prevSmallerStack;

    for (int i = heights.size() - 1; i >= 0; i--)
    { // finding next smaller element index
        while (!nextSmallerStack.empty() && heights[nextSmallerStack.top()] >= heights[i])
        {
            nextSmallerStack.pop();
        }

        if (nextSmallerStack.empty())
        {
            nextSmaller[i] = -1;
        }
        else
        {
            nextSmaller[i] = nextSmallerStack.top();
        }

        nextSmallerStack.push(i);
    }

    for (int i = 0; i < heights.size(); i++)
    { // finding prev smaller element index
        while (!prevSmallerStack.empty() && heights[prevSmallerStack.top()] >= heights[i])
        {
            prevSmallerStack.pop();
        }

        if (prevSmallerStack.empty())
        {
            prevSmaller[i] = -1;
        }
        else
        {
            prevSmaller[i] = prevSmallerStack.top();
        }

        prevSmallerStack.push(i);
    }

    int ans = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        int left = (prevSmaller[i] == -1) ? 0 : prevSmaller[i];
        int right = (nextSmaller[i] == -1) ? heights.size() : nextSmaller[i];

        int currSum = heights[i] * (right - left - 1);
        ans = max(ans, currSum);
    }

    return ans;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};

    cout << "Ans: " << largestRectangleArea(v) << endl;

    return 0;
}