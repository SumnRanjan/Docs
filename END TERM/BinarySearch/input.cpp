#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d1)
    {
        data = d1;
        left = NULL;
        right = NULL;
    }
};

node *levelorder()
{
    int root_val;
    cin >> root_val;
    if (root_val == -1)
    {
        return NULL;
    }
    node *root = new node(root_val);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        int left, right;
        cin >> left;
        if (left != -1)
        {
            front->left = new node(left);
            q.push(front->left);
        }
        cin >> right;
        if (right != -1)
        {
            front->right = new node(right);
            q.push(front->right);
        }
    }
    return root;
}

void printlevelorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* front=q.front();
        q.pop();
        if(front->left)
        {
            q.push(front->left);
        }
        if(front->right)
        {
            q.push(front->right);
        }
        cout<<front->data<<" ";
    }
}
int main()
{
    node *root = levelorder();
    printlevelorder(root);

    return 0;
}