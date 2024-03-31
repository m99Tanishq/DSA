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

bool isLeaf(Node *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

void truncate(Node *&root, int k, int target)
{
    if (!root)
    {
        return;
    }

    target += root->key;

    truncate(root->left, k, target);
    truncate(root->right, k, target);

    if (target < k and isLeaf(root))
    {
        delete (root);
        root = nullptr;
    }
}

void solve()
{
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(2);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(3);

    int k = 20;
    truncate(root, k, 0);
    inorder(root);
}