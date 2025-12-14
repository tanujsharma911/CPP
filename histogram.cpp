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

    cout << "Next smaller: ";
    for (int i = 0; i < heights.size(); i++)
    {
        cout << nextSmaller[i] << " ";
    }
    cout << endl;

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
    cout << "Prev smaller: ";
    for (int i = 0; i < heights.size(); i++)
    {
        cout << prevSmaller[i] << " ";
    }
    cout << endl;

    int ans = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        int left = (prevSmaller[i] == -1) ? 0 : prevSmaller[i];
        int right = (nextSmaller[i] == -1) ? heights.size() : nextSmaller[i];

        int currSum = heights[i] * (right - left - 1);
        cout << currSum << " ";
        ans = max(ans, currSum);
    }
    cout << endl;

    return ans;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    cout << "Q: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Ans: " << largestRectangleArea(v);

    return 0;
}