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


void deleteBinaryTree(Node *root){
    if(root == nullptr){
        return;
    }
    // postorder -> child 1st the parents (bottom up)
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    delete root;
    root = nullptr;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    // delete the entire tree
    deleteBinaryTree(root);

    if (root == nullptr)
    {
        cout << "Tree Successfully Deleted";
    }

    return 0;
}
