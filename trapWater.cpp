#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> height)
    {
        vector<int> leftMax = height;
        vector<int> rightMax = height;

        for (int i = 1; i < height.size(); i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        cout << "leftMax: ";
        for (int i = 0; i < height.size(); i++)
        {
            cout << leftMax[i] << " ";
        }
        cout << endl;

        for (int i = height.size() - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {
            int trap = min(leftMax[i], rightMax[i]) - height[i];

            if (trap > 0)
                ans += trap;
        }

        return ans;
    }
    void display(vector<int> arr)
    {
        cout << "arr: ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    vector<int> v = {4, 2, 0, 3, 2, 5};

    s.display(v);
    cout << s.trap(v) << endl;

    return 0;
}