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

// void postorder(Node *root){
//     if(root == nullptr){
//         return;
//     }

//     postorder(root->left);
//     postorder(root->right);
//     cout << root -> data << " ";
// }

void postorderIterative(Node *root){
    stack<Node *> s;
    stack<int> out;
   
    s.push(root);

        while(!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        out.push(curr -> data);

        if(curr -> left){
            s.push(curr -> left);
        }

        if (curr->right)
        {
            s.push(curr->right);
        }
    }

    while(out.empty()){
        cout << out.top() << " ";
        out.pop();
    }
}
