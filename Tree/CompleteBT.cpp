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

bool isComplete(Node *root)
{
    if (!root)
    {
        return true;
    }

    queue<Node *> q;
    q.push(root);
    bool flag = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            root = q.front();
            q.pop();
            if (root->left)
            {
                if (flag)
                {
                    return false;
                }

                q.push(root->left);
            }
            else
            {
                flag = 1;
            }

            if (root->right)
            {
                if (flag)
                {
                    return false;
                }
                q.push(root->right);
            }
            else
            {
                flag = 1;
            }
        }
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

    if (isComplete(root))
    {
        cout << "Complete binary tree";
    }
    else
    {
        cout << "Not a complete binary tree";
    }
}