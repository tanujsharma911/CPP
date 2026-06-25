/*

99. Recover Binary Search Tree

*/

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *second;

    void helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        helper(root->left);

        if (prev && root->val < prev->val)
        {
            if (first == NULL)
            {
                first = prev;
                second = root;
            }
            else
            {
                second = root;
            }
        }

        prev = root;

        helper(root->right);

        return;
    }
    void recoverTree(TreeNode *root)
    {
        prev = NULL;
        first = NULL;
        second = NULL;

        helper(root);

        if (first && second)
        {
            swap(first->val, second->val);
        }
    }
};

int main()
{

    cout << endl;
    return 0;
}