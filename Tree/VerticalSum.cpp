#include <iostream>
#include <unordered_map>
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

void printVerticalSum(Node *root, int dist, unordered_map<int, int> &mp)
{
    if (!root)
        return;

    mp[dist] += root->key;

    printVerticalSum(root->left, dist - 1, mp);
    printVerticalSum(root->right, dist + 1, mp);
}

void solve()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    unordered_map<int, int> mp;
    printVerticalSum(root, 0, mp);
    for (auto it : mp)
    {
        cout << it.second << " ";
    }
}

/*
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

void printVerticalSum(Node *root, int dist, map<int, vector<int>> &m1p){
    if(!root) return;

    m1p[dist].push_back(root->key);

    printVerticalSum(root->left, dist-1, m1p);
    printVerticalSum(root->right, dist+1, m1p);
}



void solve(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);
    map<int, vector<int>> m1p;
    printVerticalSum(root, 0, m1p);
    for(auto it : m1p){
        for(auto x : it.second){
            cout << x << " ";
        }
        cout << endl;
    }

}
*/