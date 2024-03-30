#include <iostream>
#include <queue>
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

int getDiameter(Node *root, int &diameter)
{
    if (!root)
    {
        return 0;
    }

    int left = getDiameter(root->left, diameter);
    int right = getDiameter(root->right, diameter);

    diameter = max(diameter, left + right + 1);
    return 1 + max(left, right);
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
    int diameter = 0;
    getDiameter(root, diameter);
    cout << "The diameter of the tree is " << diameter;
}