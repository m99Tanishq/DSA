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

bool isSymmetric(Node *root1, Node *root2)
{
    if (!root1 and !root2)
    {
        return true;
    }

    return ((root1 != nullptr and root2 != nullptr) and isSymmetric(root1->left, root2->right) and isSymmetric(root1->right, root2->left));
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);

    if (isSymmetric(root->left, root->right))
    {
        cout << "The binary tree is symmetric";
    }
    else
    {
        cout << "The binary tree is not symmetric";
    }
}