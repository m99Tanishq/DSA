#include <iostream>
#include <climits>
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

void findMaxSumPath(Node *root, int &maxi, int sum)
{
    if (!root)
    {
        return;
    }

    sum += root->key;

    findMaxSumPath(root->left, maxi, sum);
    findMaxSumPath(root->right, maxi, sum);
    if (!root->left and !root->right)
    {
        maxi = max(sum, maxi);
    }
    sum -= root->key;
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(10);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(5);
    int maxi = INT_MIN;
    findMaxSumPath(root, maxi, 0);
    cout << maxi << endl;
}