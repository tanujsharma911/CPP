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

int height(Node *root, int n)
{

    if (root == nullptr)
    {
        return n;
    }

    int leftHt = height(root->left, n + 1);
    int rightHt = height(root->right, n + 1);

    return max(leftHt, rightHt);
}

int count(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = count(root->left);
    int right = count(root->right);

    return left + right + 1;
}

int sum(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = sum(root->left);
    int right = sum(root->right);

    return root->data + left + right;
}

int minAns = INT_MAX;
int minNode(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    minAns = min(root->data, minAns);

    minNode(root->left);
    minNode(root->right);

    return minAns;
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

bool identical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    if (root1->data != root2->data)
        return false;

    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);

    return left && right;
}

void kthLevel(Node *root, int k)
{

    int currLevel = 1;
    deque<Node *> d;
    d.push_back(root);
    d.push_back(nullptr);

    while (!d.empty())
    {
        Node *temp = d.front();
        d.pop_front();

        if (temp == nullptr)
        {
            if (d.empty())
            {
                break;
            }
            d.push_back(nullptr);
            currLevel++;
            continue;
        }

        if (currLevel == k)
        {
            cout << temp->data << " ";
        }

        if (temp->left)
        {
            d.push_back(temp->left);
        }
        if (temp->right)
        {
            d.push_back(temp->right);
        }
    }
}

int main()
{

    vector<int> v = {50, 24, 20, -1, -1, 30, -1, -1, 75, 65, -1, -1, 85, -1, -1};
    vector<int> v2 = {50, 24, 21, -1, -1, 30, -1, -1, 75, 65, -1, -1, 85, -1, -1};

    Node *root = build(v);
    i = -1;
    Node *root2 = build(v2);
    cout << "Height: " << height(root, 0) << endl;
    cout << "Number of nodes: " << count(root) << endl;
    cout << "Sum of nodes: " << sum(root) << endl;
    cout << "Minimum of nodes: " << minNode(root) << endl;
    cout << "InOrder: ";
    inOrderDisplay(root);
    cout << "\nPreOrder: ";
    preOrderDisplay(root);
    cout << "\nLevelOrder: \n";
    levelOrder(root);
    cout << "\nIndentical: " << identical(root, root2) << endl;
    cout << 4 << "th level of tree: \n";
    kthLevel(root, 3);
    cout << endl;

    return 0;
}