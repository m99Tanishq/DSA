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

void sink(Node *root)
{

    if (root == nullptr)
    {
        return;
    }

    if (root->left && root->left->key != 0)
    {

        swap(root->key, root->left->key);
        sink(root->left);
    }

    else if (root->right && root->right->key != 0)
    {
        swap(root->key, root->right->key);
        sink(root->right);
    }
}

void sinkNodes(Node *&root)
{

    if (root == nullptr)
    {
        return;
    }

    sinkNodes(root->left);
    sinkNodes(root->right);

    if (root->key == 0)
    {
        sink(root);
    }
}

void solve()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(2);
    root->right->left->left = new Node(3);
    root->right->left->right = new Node(4);
    sinkNodes(root);
    inorder(root);
}
