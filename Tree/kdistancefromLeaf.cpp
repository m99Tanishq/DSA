#include <iostream>
#include <unordered_set>
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

bool isLeaf(Node *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

void leafNodeDistance(Node *node, vector<Node *> path,
                      unordered_set<Node *> &set, int dist)
{
    // base case: empty tree
    if (node == nullptr)
    {
        return;
    }

    // if a leaf node is found, insert the node at a distance `dist` from the
    // leaf node into the set
    if (isLeaf(node) && path.size() >= dist)
    {
        set.insert(path.at(path.size() - dist));
        return;
    }

    // include the current node in the current path
    path.push_back(node);

    // recur for the left and right subtree
    leafNodeDistance(node->left, path, set, dist);
    leafNodeDistance(node->right, path, set, dist);
}

void solve()
{
    Node *node = new Node(15);
    node->left = new Node(10);
    node->right = new Node(20);
    node->left->left = new Node(8);
    node->left->right = new Node(12);
    node->right->left = new Node(16);
    node->right->right = new Node(25);
    node->right->left->left = new Node(18);

    int dist = 1;
    vector<Node *> path;
    unordered_set<Node *> set;

    leafNodeDistance(node, path, set, dist);

    for (Node *x : set)
    {
        cout << x->key << " ";
    }
}