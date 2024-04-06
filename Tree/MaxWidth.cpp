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

void findMaxWidth(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    int maxi = 0;

    while (!q.empty())
    {
        int size = q.size();
        maxi = max(size, maxi);
        while (size--)
        {
            root = q.front();
            q.pop();

            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
    }
    cout << maxi << endl;
}

void solve()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    findMaxWidth(root);
}