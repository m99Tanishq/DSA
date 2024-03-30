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

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    findLCA(root, root->right->left->left, root->right->right);
    findLCA(root, root->right->left->left, new Node(10));
    findLCA(root, root->right->left->left, root->right->left->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->left, root->right->left);
}