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

Node *createTree(vector<int> &tree)
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
        Node *curr = q.front();
        q.pop();

        if (tree[i] != -1)
        {
            curr->left = new Node(tree[i]);
            q.push(curr->left);
        }
        i++;

        if (tree[i] != -1 && i < tree.size())
        {
            curr->right = new Node(tree[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

Node * treebanajarahahumai(vector<int>&tree){
    if(tree.empty()){
        return NULL;
    }

    Node * root = new Node(tree[0]);
    queue<Node *>q;
    q.push(root);
    int i = 1;

    while(i < tree.size()){
        Node * curr = q.front();
        q.pop();

        if(tree[i] != -1){
            curr->left = new Node(tree[i]);
            q.push(curr->left);
        }
        i++;

        if(tree[i] != 1 && i < tree.size()){
            curr->right = new Node(tree[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

Node * ct(vector<int>&tree){
    if(tree.empty()){
        return NULL;
    }

    Node * root = new Node(tree[0]);
    queue<Node * > q;
    q.push(root);
    int i = 1;

    while(i < tree.size()){
        Node * front = q.front();
        q.pop();

        if(tree[i] != -1){
            front->left = new Node(tree[i]);
            q.push(front->left);
        }
        i++;

        if(tree[i] != -1 && i < tree.size()){
            front->right = new Node(tree[i]);
            q.push(front->right);
        }
        i++;
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

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << front->data << endl;

        if (front->left)
        {
            q.push(front->left);
        }

        if (front->right)
        {
            q.push(front->right);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    Node *root = ct(tree);
    cout << "Print" << " " << endl;
    // inorder(root);
    levelOrder(root);
}