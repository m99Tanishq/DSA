#include <iostream>
#include <list>
using namespace std;
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

void spiralOrderTraversal(Node *root)
{
    if (!root)
        return;

    list<Node *> deque;
    deque.push_front(root);
    bool flag = 1;

    while (!deque.empty())
    {
        int nodecount = deque.size();

        if (flag)
        {
            while (nodecount)
            {
                Node *curr = deque.front();
                deque.pop_front();

                cout << curr->key << " ";

                if (curr->left)
                {
                    deque.push_back(curr->left);
                }
                if (curr->right)
                {
                    deque.push_back(curr->right);
                }
                nodecount--;
            }
        }
        else
        {
            while (nodecount)
            {
                Node *curr = deque.back();
                deque.pop_back();

                cout << curr->key << " ";

                if (curr->right)
                {
                    deque.push_front(curr->right);
                }

                if (curr->left)
                {
                    deque.push_front(curr->left);
                }
                nodecount--;
            }
        }
        flag = !flag;
        cout << endl;
    }
}

void solve()
{

    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    spiralOrderTraversal(root);
}