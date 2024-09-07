#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
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
node *construct(vector<int> arr, int n)
{
    if (n == 0)
    {
        return NULL;
    }
    node *root = new node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, arr[i]);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node *inordertobst(vector<int> arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = inordertobst(arr, s, mid - 1);
    root->right = inordertobst(arr, mid + 1, e);
    return root;
}
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
        {

            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}
int main()
{
    // here n denote total number of test case;
    int n;
    cin >> n;
    while (n--)
    {
        vector<int> arr;
        arr = {1, 2, 3, 4, 5};
        int s = 0;
        int e = n - 1;
        // node*root=construct(arr,n);
        node *root = inordertobst(arr, s, e);
        cout << "inorder " << endl;
        // inorder(root);
        cout << endl;
        levelorder(root);
    }
    
}