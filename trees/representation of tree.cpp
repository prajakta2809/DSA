/* 
traversal techniques DFS and BFS
in dfs : inorder,pre-order and post-order

*/


#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
   struct node *left;
    struct node *right;
    node(int val){
        data=val;
        right=left=NULL;
    }
};

void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void post(struct node *root){
    if(root==NULL){
        return;
    }
    
    post(root->left);
   
    post(root->right);
     cout<<root->data<<" ";
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

//BFS
void bfs(node* root){
    
    if(root==NULL){
        return;
    }
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            level.push_back(temp->data);
            cout<<temp->data<<" ";
        }
        ans.push_back(level);
    }
}


int main(){
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    cout<<"preorder"<<" ";
    preorder(root);
    cout<<"postorder"<<" ";
    post(root);
    cout<<"inorder"<<" ";
    inorder(root);
    cout<<"bfs ";
    bfs(root);
    return 0;
}

