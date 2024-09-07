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

Node *create(vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (i < arr.size())
    {
        Node *front = q.front();
        q.pop();
        if (arr[i] != -1)
        {
            front->left = new Node(arr[i]);
            q.push(front->left);
        }
        i++;
        if (arr[i] != -1 && i < arr.size())
        {
            front->right = new Node(arr[i]);
            q.push(front->right);
        }
        i++;
    }
    return root;
}
int maxDepth(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight) + 1;
    
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = maxDepth(root->left) + maxDepth(root->right);
    return max(max(option1, option2), option3);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    int diff = abs(lh - rh);

    bool ans = (diff <= 1);

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if (ans && left && right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = create(arr);

    cout << "Printing height of tree: " << endl;
    int heightOfTree = maxDepth(root);
    cout << heightOfTree<<endl;

    // cout << "Diameter of tree: " << endl;
    // int diameterOfTree = diameter(root);
    // cout << diameterOfTree;
    // cout << endl;

    // cout << "Balanced or not" << endl;
    // if (isBalanced(root))
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    return 0;
}