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

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

Node *ConstBst(vector<int> tree, int n)
{
    if (n == 0)
        return NULL;

    Node *root = new Node(tree[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, tree[i]);
    }
    return root;
}


void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// vector<vector<int>> levelOrder(Node *root)
// {
//     vector<vector<int>> ans;
//     if (root == NULL)
//     {
//         return ans;
//     }
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> level;

//         for (int i = 0; i < size; i++)
//         {
//             Node *fornt = q.front();
//             q.pop();

//             level.push_back(fornt->data);

//             if (fornt->left)
//             {
//                 q.push(fornt->left);
//             }

//             if (fornt->right)
//             {
//                 q.push(fornt->right);
//             }
//         }
//         ans.push_back(level);
//     }

//     return ans;
// }

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

        cout << front->data << " ";
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

    Node *root = ConstBst(tree, n);
    // inorder(root);
    vector<vector<int>> ans;
    levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}