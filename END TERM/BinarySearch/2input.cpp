#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node *level()
{
    int rootval;
    cin >> rootval;

    if (rootval == -1)
    {
        return nullptr;
    }

    Node *root = new Node(rootval);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int left, right;
        cin >> left;
        if (left != -1)
        {
            front->left = new Node(left);
            q.push(front->left);
        }

        cin >> right;
        if (right != -1)
        {
            front->right = new Node(right);
            q.push(front->right);
        }
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = level();
    inorder(root);
}