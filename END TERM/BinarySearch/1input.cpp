#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createtree(vector<int> &tree)
{
    if (tree.empty())
    {
        return NULL;
    }
    Node *root = new Node(tree[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (i < tree.size())
    {
        Node *current = q.front();
        q.pop();
        if (tree[i] != -1)
        {
            current->left = new Node(tree[i]);
            q.push(current->left);
        }
        i++;
        if (tree[i] != -1 && i < tree.size())
        {
            current->right = new Node(tree[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
// this is for printing

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
int main()
{

    int n;
    cout << "No of nodes: " << endl;
    cin >> n;

    vector<int> tree(n);
    cout << "enter the values of tree: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    Node *root = createtree(tree);
    cout << "printing inorder: " << endl;
    inorder(root);
    return 0;
}    