#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node *find(Node *root, int data)
{
    Node *temp = root;
    int pass = 1;

    while (temp != nullptr && temp->data != data)
    {
        cout << "pass: " << pass++ << endl;
        if (temp->data == data)
        {
            return temp;
        }
        else if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return temp;
}

static int i = -1;
Node *build(vector<int> v)
{
    i++;

    if (v[i] == -1)
    {
        return nullptr;
    }

    Node *root = new Node(v[i]);

    root->left = build(v);
    root->right = build(v);

    return root;
}

void preOrderDisplay(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrderDisplay(root->left);
    preOrderDisplay(root->right);
}

void inOrderDisplay(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderDisplay(root->left);

    cout << root->data << " ";

    inOrderDisplay(root->right);
}

void levelOrder(Node *root)
{
    deque<Node *> s;
    s.push_back(root);
    s.push_back(nullptr);

    if (root == nullptr)
    {
        return;
    }

    while (!s.empty())
    {
        Node *curr = s.front();
        s.pop_front();
        if (curr == nullptr)
        {
            if (!s.empty())
            {
                cout << endl;
                s.push_back(nullptr);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != nullptr)
        {
            s.push_back(curr->left);
        }
        if (curr->right != nullptr)
        {
            s.push_back(curr->right);
        }
    }
}

vector<int> morris(Node *root)  // converts tree into inorder vector
{
    vector<int> ans;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *IP = curr->left;
            while (IP->right != nullptr && IP->right != curr)
            {
                IP = IP->right;
            }

            if (IP->right)
            {
                IP->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                IP->right = curr;
                curr = curr->left;
            }
        }
    }

    return ans;
}

int main()
{

    vector<int> v = {50, 24, 20, -1, -1, 30, -1, -1, 75, 65, -1, -1, 85, -1, -1};

    Node *root = build(v);
    cout << "InOrder: ";
    inOrderDisplay(root);
    cout << "\nPreOrder: ";
    preOrderDisplay(root);
    cout << "\nLevelOrder: \n";
    levelOrder(root);
    cout << endl;

    vector<int> preOrder2 = morris(root);
    for (int i = 0; i < preOrder2.size(); i++)
    {
        cout << preOrder2[i] << " ";
    }

    cout << endl;

    return 0;
}