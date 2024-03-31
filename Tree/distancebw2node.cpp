#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

Node *findLCA(Node *root, Node *x, Node *y)
{
    if (!root)
        return NULL;

    if (root == x || root == y)
        return root;

    Node *left = findLCA(root->left, x, y);
    Node *right = findLCA(root->right, x, y);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    return root;
}

int Distance(Node *root, Node *node)
{
    if (!root)
        return 0;

    if (root == node)
    {
        return 1;
    }

    int left = Distance(root->left, node);
    int right = Distance(root->right, node);

    if (!left and !right)
    {
        return 0;
    }
    else
    {
        return left + right + 1;
    }
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);
    Node *LCA = findLCA(root, root->right->right, root->right->left->left);
    int x = Distance(LCA, root->right->right);
    int y = Distance(LCA, root->right->left->left);

    cout << x + y - 2 << endl;
}