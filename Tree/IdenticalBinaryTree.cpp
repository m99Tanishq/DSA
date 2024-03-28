#include <iostream>
using namespace std;

// Data structure to store a binary tree node
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

bool isIdentical(Node *x, Node *y){
    if(x == nullptr and y == nullptr){
        return 1;
    }
    return ((x and y) and (x->key == y-> key) and isIdentical(x->left,y->left) and (isIdentical(x->right, y->right)));
}

int main()
{
    // construct the first tree
    Node *x = nullptr;

    x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);

    // construct the second tree
    Node *y = nullptr;

    y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(25);

    if (isIdentical(x, y))
    {
        cout << "The given binary trees are identical";
    }
    else
    {
        cout << "The given binary trees are not identical";
    }

    return 0;
}