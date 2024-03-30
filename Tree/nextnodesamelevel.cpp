#include <iostream>
#include <list>
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

Node *findRightNode(Node *root, Node *node)
{
    if (!root)
        return nullptr;

    list<Node *> q;
    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            root = q.front();
            q.pop_front();

            if (root == node)
            {
                if (size == 0)
                {
                    return nullptr;
                }
                return q.front();
            }

            if (root->left)
            {
                q.push_back(root->left);
            }

            if (root->right)
            {
                q.push_back(root->right);
            }
        }
    }
    return nullptr;
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    Node *right = findRightNode(root, root->left->right);

    if (right)
    {
        cout << "Right node is " << right->key;
    }
    else
    {
        cout << "Right node doesn't exist";
    }
}