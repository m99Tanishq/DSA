#include <iostream>
#include <unordered_map>
#include <vector>
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

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

Node *createTree(vector<int> &parent)
{
    int n = parent.size();

    unordered_map<int, Node *> map;
    for (int i = 0; i < n; i++)
    {
        map[i] = new Node(i);
    }

    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            root = map[i];
        }
        else
        {
            Node *ptr = map[parent[i]];
            if (ptr->left)
            {
                ptr->right = map[i];
            }
            else
            {
                ptr->left = map[i];
            }
        }
    }
    return root;
}

void solve()
{
    vector<int> parent = {-1, 0, 0, 1, 2, 2, 4, 4};
    Node *root = createTree(parent);
    inorder(root);
}