#include <iostream>
#include <stack>
using namespace std;

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

// void preorder(Node *root){

//     if(root == nullptr){
//         return;
//     }
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

void iterativePreorder(Node *root){
    stack<Node *> s;
    Node *curr = root;
    s.push(root);

    while(!s.empty()){
          curr = s.top();
          s.pop();
          cout << curr->data << " ";
          if(!(curr -> right)){
            s.push(curr->right);
          }
          if(!(curr -> left)){
            s.push(curr -> left);
          }
    }
}