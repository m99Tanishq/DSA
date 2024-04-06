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

int isHeightBalanced(Node *root, bool &flag)
{
    if (!root || flag)
        return 0;

    int left = isHeightBalanced(root->left, flag);
    int right = isHeightBalanced(root->right, flag);

    if (abs(left - right) > 1)
    {
        flag = 1;
    }

    return max(left, right) + 1;
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    bool flag = 1;
    isHeightBalanced(root, flag);
    if (flag)
    {
        cout << "Binary tree is balanced";
    }
    else
    {
        cout << "Binary tree is not balanced";
    }
}