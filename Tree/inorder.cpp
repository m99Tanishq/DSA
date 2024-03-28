#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// void inorder(Node *root){
//     if(root == nullptr){
//         return;
//     }

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

void inorderIterative(Node *root){
    stack<Node *> s;
    Node *curr =root;

    while(!s.empty() || curr != nullptr){
        if(curr != nullptr){
            s.push(curr);
            curr = curr -> left;
        }
        else{
            curr = s.top();
            s.pop();
            cout << curr -> data << " ";
            curr = curr -> right;
        }
    }
}