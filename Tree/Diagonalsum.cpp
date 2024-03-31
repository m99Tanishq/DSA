#include <iostream>
#include <unordered_map>
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

void diagonalSum(Node *root, int dia, unordered_map<int, int> &map)
{
    if (!root)
    {
        return;
    }

    map[dia] += root->key;
    diagonalSum(root->left, dia + 1, map);
    diagonalSum(root->right, dia, map);
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    unordered_map<int, int> map;
    diagonalSum(root, 0, map);
    for (auto it : map)
    {
        cout << it.second << " ";
    }
}