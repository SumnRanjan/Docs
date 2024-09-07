#include <bits/stdc++.h>
using namespace std;
class Node{
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

Node *insertIntoBst(Node *root , int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBst(root->right , data);
    }
    else{
        root->left = insertIntoBst(root->left , data);
    }

    return root;
}

void createBST(Node *&root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBst(root , data);
        cin>>data;
    }
}

void levelorder(Node * root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node * front = q.front();
        q.pop();

        
        cout<<front->data<<" ";

        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }

    }
}

int main(){
    Node * root = NULL;
    createBST(root);
    levelorder(root);
    return 0;
}