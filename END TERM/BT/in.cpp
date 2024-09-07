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
node *createtree(vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }
    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        node *curr = q.front();
        q.pop();
        if (arr[i] != -1)
        {
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (arr[i] != -1 && i < arr.size())
        {
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
void pre(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int h = max(left, right) + 1;
    return h;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right);
    int dia = max(opt1, max(opt2, opt3));
    return dia;
}
bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int dif = abs(lh - rh);
    bool curr = dif <= 1;
    bool ra = isbalanced(root->right);
    bool la = isbalanced(root->left);
    if (curr && ra && la)
    {
        return true;
    }
    else
    {
        return false;
    }
}
node *lca(node *root, node *p, node *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data)
    {
        return p;
    }
    if (root->data == q->data)
    {
        return q;
    }
    node *la = lca(root->left, p, q);
    node *ra = lca(root->right, p, q);
    if (la == NULL && ra == NULL)
    {
        return NULL;
    }
    else if (la != NULL && ra == NULL)
    {
        return la;
    }
    else if (la == NULL && ra != NULL)
    {
        return ra;
    }
    else
    {
        return root;
    }
}
// ignore this code find node
node *findNode(node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == val)
    {
        return root;
    }
    node *leftSearch = findNode(root->left, val);
    if (leftSearch != nullptr)
    {
        return leftSearch;
    }
    return findNode(root->right, val);
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

int main()
{
    vector<int> a;
    a = {8, 7, 6, 4, 3, 2, 1, 9, 0, 11, 12, 13};
    node *root = createtree(a);
    // pre(root);
    // cout<<"inorder "<<endl;
    // inorder(head);
    // cout<<endl;
    //  cout<<"here is height of tree"<<endl;
    //   int p=height(root);
    //   cout<<p<<endl;
    // // cout<<endl;
    // int dia=diameter(root);
    // cout<<dia<<endl;

    // code for checking balanced tree
    // bool ans=isbalanced(root);
    // if(ans){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }

    //  code for lca(lowest common ansector)
    node *p = new node(2);
    node *q = new node(1);
    node *ans = lca(root, p, q);
    cout << ans->data << endl;
}