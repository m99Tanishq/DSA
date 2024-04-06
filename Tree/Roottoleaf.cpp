#include <iostream>
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

void printRootToLeafPaths(Node *root, vector<int> &path)
{
    if (!root)
        return;
    path.push_back(root->key);

    if (root->left == nullptr and root->right == nullptr)
    {
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    /* Reverse Leaf to Root
    if(!root->left and !root->right){
        for(auto it = path.rbegin(); it != path.rend(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }*/

    printRootToLeafPaths(root->left, path);
    printRootToLeafPaths(root->right, path);

    path.pop_back();
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
    root->right->left->left = new Node(8);
    root->right->right->right = new Node(9);
    vector<int> path;
    // print all root-to-leaf paths
    printRootToLeafPaths(root, path);
}