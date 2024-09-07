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

Node *createTree1(vector<int> &tree)
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

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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

void zig(Node *root, vector<vector<int>> &ans)
{
    // vector<vector<int>>ans;
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    bool ltor = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> oneLevel(size);

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            int index = ltor ? i : size - i - 1;
            oneLevel[index] = front->data;

            if (front->left)
            {
                q.push(front->left);
            }

            if (front->right)
            {
                q.push(front->right);
            }
        }
        ans.push_back(oneLevel);
        ltor = !ltor;
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

int diameter(Node *root, int &D)
{

    if (root == NULL)
        return 0;

    int left = diameter(root->left, D);
    int right = diameter(root->right, D);

    int currD = left + right + 1;
    D = max(currD, D);

    return max(left, right) + 1;
}

int height1(Node *root, bool ans)
{
    if (root == NULL)
        return 0;

    int left = height1(root->left, ans);
    int right = height1(root->right, ans);

    if (ans && abs(left - right) > 1)
    {
        ans = false;
    }

    return max(left, right) + 1;
}

bool isBal(Node *root)
{
    bool ans = true;
    height1(root, ans);
    return ans;
}

Node *lca(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == p->data)
        return p;

    if (root->data == q->data)
        return q;

    Node *leftans = lca(root->left, p, q);
    Node *rightans = lca(root->right, p, q);

    if (leftans == NULL && rightans == NULL)
    {
        return nullptr;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }

    else
    {
        return root;
    }
}

void leftview(Node *root, int level, vector<int> &left)
{
    if (root == NULL)
        return;

    if (level == left.size())
    {
        left.push_back(root->data);
    }

    leftview(root->left, level + 1, left);
    leftview(root->right, level + 1, left);
}

void Rightview(Node *root, int level, vector<int> &right)
{
    if (root == NULL)
        return;

    if (level == right.size())
    {
        right.push_back(root->data);
    }

    Rightview(root->right, level + 1, right);
    Rightview(root->left, level + 1, right);
}

void topview(Node *root)
{
    map<int, int> hdtonod;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *front = temp.first;
        int hd = temp.second;

        if (hdtonod.find(hd) == hdtonod.end())
        {
            hdtonod[hd] = front->data;
        }

        if (front->left)
        {
            q.push(make_pair(front->left, hd - 1));
        }

        if (front->right)
        {
            q.push(make_pair(front->right, hd + 1));
        }
    }

    for (auto i : hdtonod)
    {
        cout << i.second << " ";
    }
}

void bottomview(Node *root)
{
    map<int, int> hdtonod;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *front = temp.first;
        int hd = temp.second;

        hdtonod[hd] = front->data;

        if (front->left)
        {
            q.push(make_pair(front->left, hd - 1));
        }

        if (front->right)
        {
            q.push(make_pair(front->right, hd + 1));
        }
    }

    for (auto i : hdtonod)
    {
        cout << i.second << " ";
    }
}

void leftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout << root->data << " ";

    if (root->left != NULL)
    {
        leftBoundary(root->left);
    }
    else
    {
        leftBoundary(root->right);
    }
}

void leafNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    leafNode(root->left);
    leafNode(root->right);
}

void rightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right != NULL)
    {
        rightBoundary(root->right);
    }
    else
    {
        rightBoundary(root->left);
    }

    cout << root->data << " ";
}

void Boundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    leftBoundary(root->left);
    leafNode(root->left);
    leafNode(root->right);
    rightBoundary(root->right);
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
    Node *root = createTree(tree);

    // vector<int> a;
    // a = {8, 7, 6, 4, 3, 2, 1, 9, 0, 11, 12, 13};
    // Node *root = createTree(a);

    // cout<<"Preorder"<<endl;
    // preOrder(root);
    // levelOrder(root);
    // vector<vector<int>>ans;
    // zig(root , ans);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //        cout<< ans[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }

    // int ans = height(root);
    // cout << ans << endl;
    // int D = 0;
    // diameter(root , D);
    // cout<<D<<endl;

    // bool ans = isBal(root);
    // if(ans){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // Node *p = new Node(2);
    // Node *q = new Node(1);

    // Node *ans = lca(root, p, q);
    // cout << ans->data << endl;

    // leftview
    //  vector<int>ans;
    //  leftview(root , 0 , ans);
    //  for(int i = 0 ; i < ans.size() ; i++){
    //      cout<<ans[i]<<" ";
    //  }

    // rightview
    // vector<int> ans;
    // Rightview(root, 0, ans);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // topview(root);
    // bottomview(root);
    Boundary(root);
    return 0;
}
