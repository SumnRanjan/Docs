#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(vector<int>& res){
    if(res.empty()){
        return NULL;
    }
    Node* root = new Node(res[0]);
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(i<res.size()){
        Node* front = q.front();
        q.pop();
        if(res[i] != -1){
            front->left = new Node(res[i]);
            q.push(front->left);
        }
        i++;
        if(i< res.size() && res[i] != -1 ){
            front->right = new Node(res[i]);
            q.push(front->right); 
        }
        i++;
    }
    return root;
}
void leftNodes(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        leftNodes(root->left);
    }
    else{
        leftNodes(root->right);
    }
}

void leafNodes(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    leafNodes(root->left);
    leafNodes(root->right);  
}

void rightNodes(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right != NULL){
        rightNodes(root->right);
    }
    else{
        rightNodes(root->left);
    }
    cout<<root->data<<" ";
}
void boundaryNodes(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";

    // Print left boundary excluding the leaf node
    if (root->left != NULL) {
        leftNodes(root->left);
    }

    // Print all leaf nodes
    leafNodes(root->left);
    leafNodes(root->right);

    // Print right boundary excluding the leaf node
    if (root->right != NULL) {
        rightNodes(root->right);
    }
}
// void boundaryNodes(Node* root){
//     if(root == NULL){
//         return;
//     }
//     leftNodes(root);
//     leafNodes(root);
//     if(root->right != NULL){
//         rightNodes(root->right);
//     }
//     else{
//         rightNodes(root->left);
//     }
// }

int main(){
    int n;
    cin >> n;

    vector<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    Node* root = createTree(tree);
    cout<<"printing boundary nodes: "<<endl;
    boundaryNodes(root);


return 0;
}