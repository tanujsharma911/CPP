/*

Node and Ancestor Max Diff

Given the root of a binary tree, find the maximum difference between an ancestor
node A and its descendant node B, i.e., maximize A - B.

*/

#include <iostream>

using namespace std;

/* Structure of Binary Tree Node */
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

class Solution
{
public:
  int ans = INT_MIN;

  int helper(Node *root)
  {
    if (root == NULL)
      return INT_MAX;

    int left = helper(root->left);
    int right = helper(root->right);

    ans = max({ans, root->data - left, root->data - right});

    return min({root->data, left, right});
  }
  int maxDiff(Node *root)
  {
    helper(root);

    return ans;
  }
};

int main()
{

  cout << endl;
  return 0;
}