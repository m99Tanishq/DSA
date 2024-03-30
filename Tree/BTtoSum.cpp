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

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int transform(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int left = transform(root->left);
    int right = transform(root->right);

    int old = root->key;
    root->key = left + right;

    return old + root->key;
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
    root->right->left->right = new Node(8);

    transform(root);
    preorder(root);
}

// isBT -> BTsum

/* struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

int isSumTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left and !root->right)
    {
        return root->key;
    }

    int left = isSumTree(root->left);
    int right = isSumTree(root->right);

    if ((left != INT_MIN) and (right != INT_MIN) and root->key == (left + right))
    {
        return 2 * root->key;
    }
    return INT_MIN;
}

void solve()
{
    Node *root = new Node(44);
    root->left = new Node(9);
    root->right = new Node(13);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isSumTree(root) != INT_MIN)
    {
        cout << "Binary tree is a sum tree";
    }
    else
    {
        cout << "Binary tree is not a sum tree";
    }
}
*/