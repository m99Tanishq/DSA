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

void printAllCousins(Node *root, Node *target)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    bool flag = 1;
    while (!q.empty() and flag)
    {
        int size = q.size();
        while (size--)
        {
            root = q.front();
            q.pop();
            if (root->left == target || root->right == target)
            {
                flag = 0;
            }
            else
            {
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
    }
    while (!q.empty())
    {
        cout << q.front()->key << " ";
        q.pop();
    }
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

    printAllCousins(root, root->right->left);
}