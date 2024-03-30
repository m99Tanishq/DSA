#include <iostream>
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

bool equal(Node *x, Node *y)
{
    if (!x and !y)
        return true;

    return ((x and y) and (x->key == y->key) and ((equal(x->left, y->left) and equal(x->right, y->right)) || (equal(x->left, y->right) and equal(x->right, y->left))));
}

void solve()
{
    // construct the first tree
    Node *X = nullptr;

    X = new Node(6);
    X->left = new Node(3);
    X->right = new Node(8);
    X->left->left = new Node(1);
    X->left->right = new Node(7);
    X->right->left = new Node(4);
    X->right->right = new Node(2);
    X->right->left->left = new Node(1);
    X->right->left->right = new Node(7);
    X->right->right->right = new Node(3);

    // construct the second tree
    Node *Y = nullptr;

    Y = new Node(6);
    Y->left = new Node(8);
    Y->right = new Node(3);
    Y->left->left = new Node(2);
    Y->left->right = new Node(4);
    Y->right->left = new Node(7);
    Y->right->right = new Node(1);
    Y->left->left->left = new Node(3);
    Y->left->right->left = new Node(1);
    Y->left->right->right = new Node(7);

    if (equal(X, Y))
    {
        cout << "Binary tree can be converted";
    }
    else
    {
        cout << "Binary tree cannot be converted";
    }
}