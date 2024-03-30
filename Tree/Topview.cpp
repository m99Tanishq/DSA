#include <iostream>
#include <map>
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

void topView(Node *root, int dist, int level, map<int, pair<int, int>> &mp)
{
    if (!root)
    {
        return;
    }

    if (mp.find(dist) == mp.end() || level < mp[dist].second)
    {
        mp[dist] = {root->key, level};
    }

    topView(root->left, dist - 1, level + 1, mp);
    topView(root->right, dist + 1, level + 1, mp);
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

    map<int, pair<int, int>> mp;
    topView(root, 0, 0, mp);
    for (auto it : mp)
    {
        cout << it.second.first << " ";
    }
}