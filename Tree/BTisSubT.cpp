#include <iostream>
#include <queue>
#include "../../../../../../usr/include/c++/11/bits/algorithmfwd.h"
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

void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right, v);
}

void postorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->key);
}

bool checkSubtree(Node *root, Node *subtree)
{
    if (root == subtree)
        return true;
    if (!root)
        return false;

    vector<int> a, b;
    inorder(root, a);
    inorder(subtree, b);

    auto it1 = search(a.begin(), a.end(), b.begin(), b.end());
    if (it1 == a.end())
    {
        return false;
    }

    a.clear();
    b.clear();
    postorder(root, a);
    postorder(subtree, b);

    auto it2 = search(a.begin(), a.end(), b.begin(), b.end());
    if (it2 == a.end())
    {
        return false;
    }

    return true;
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

    checkSubtree(root, root->right) ? cout << "Yes" : cout << "No";
}
