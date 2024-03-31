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

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

Node *truncate(Node *root)
{
    if (!root)
    {
        return NULL;
    }

    root->left = truncate(root->left);
    root->right = truncate(root->right);

    if ((root->left and root->right) || (root->left == NULL and root->right == NULL))
    {
        return root;
    }
    Node *child = (root->left) ? root->left : root->right;
    delete root;
    return child;
}

void solve()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->left = new Node(4);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root = truncate(root);
    inorder(root);
}