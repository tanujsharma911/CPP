/*
85. Maximal Rectangle

Link:- https://leetcode.com/problems/maximal-rectangle

Similar to [histogram.cpp] but extanted

Given a rows x cols binary matrix filled with 0's and 1's,
find the largest rectangle containing only 1's and return its area.


Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

*/

#include <iostream>

using namespace std;

vector<vector<int>> generatePrefix(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> prefixLevelVice(rows, vector<int>(cols, 0));

    for (int c = 0; c < cols; c++)
    {
        if (matrix[0][c] == '1')
            prefixLevelVice[0][c] = 1;
    }
    for (int r = 1; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (matrix[r][c] == '1')
            {
                prefixLevelVice[r][c] = prefixLevelVice[r - 1][c] + 1;
            }
        }
    }

    return prefixLevelVice;
}

vector<int> getPrevSmaller(vector<int> &heights)
{
    int n = heights.size();

    vector<int> prevSmaller(n, 0);
    stack<int> prevSmallerStack; // Stores indicies

    for (int i = 0; i < n; i++)
    {
        int height = heights[i];

        while (!prevSmallerStack.empty() && heights[prevSmallerStack.top()] >= height)
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

    return prevSmaller;
}

vector<int> getNextSmaller(vector<int> &heights)
{
    int n = heights.size();

    vector<int> nextSmaller(n, 0);
    stack<int> nextSmallerStack; // Stores indicies

    for (int i = n - 1; i >= 0; i--)
    {
        int height = heights[i];

        while (!nextSmallerStack.empty() && heights[nextSmallerStack.top()] >= height)
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

    return nextSmaller;
}

int largestRectangleInHistogram(vector<int> &heights)
{
    int n = heights.size();

    int largetRectangle = 0;

    vector<int> prevSmaller = getPrevSmaller(heights);
    vector<int> nextSmaller = getNextSmaller(heights);

    for (int i = 0; i < n; i++)
    {
        int left = (prevSmaller[i] == -1) ? 0 : prevSmaller[i] + 1;
        int right = (nextSmaller[i] == -1) ? n - 1 : nextSmaller[i] - 1;

        int area = heights[i] * (right - left + 1);

        largetRectangle = max(largetRectangle, area);
    }

    return largetRectangle;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> prefixLevelVice = generatePrefix(matrix);

    int largestRectangle = 0;

    for (int r = 0; r < rows; r++)
    {
        vector<int> heights = prefixLevelVice[r];

        int thisHistogramMaxRectangle = largestRectangleInHistogram(heights);

        largestRectangle = max(largestRectangle, thisHistogramMaxRectangle);
    }

    return largestRectangle;
}

int main()
{
    // vector<vector<char>> matrix = {
    //     {'1', '0', '1', '0', '0'},
    //     {'1', '0', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix = {
        {'0'}};

    cout << maximalRectangle(matrix) << endl;

    return 0;
}