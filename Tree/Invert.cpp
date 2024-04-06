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

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to invert a given binary tree using preorder traversal
void invertBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

    swap(root->left, root->right);
}

void solve()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    invertBinaryTree(root);
    preorder(root);
}
