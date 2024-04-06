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

void printRightView(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int n = size;
        while (size)
        {
            root = q.front();
            q.pop();
            if (size == 1)
            {
                cout << root->key << " ";
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            size--;
        }
    }
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

    printRightView(root);
}