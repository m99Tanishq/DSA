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

void leftview(Node *root, int level, int &lastlevel)
{
    if (!root)
    {
        return;
    }

    if (lastlevel < level)
    {
        cout << root->key << " ";
        lastlevel = level;
    }

    leftview(root->left, level + 1, lastlevel);
    leftview(root->right, level + 1, lastlevel);
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
    int lastlevel = 0;
    leftview(root, 1, lastlevel);
}