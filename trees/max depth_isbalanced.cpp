

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

int isBalanced(node* root){
    if(root==NULL){
        return 0;
    }
    int l=isBalanced(root->left);
    int r=isBalanced(root->right);
    
    if(l== -1 && r== -1){
        return -1;
    }
    if(abs(r-l)>1){
        return -1;
    }
    return 1+max(l,r);
    
}

int maxDepth(node* root){
    if(root==NULL){
        return 0;
    }
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+max(l,r);
}

int main(){
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    cout<<maxDepth(root);
    cout<<endl;
    cout<<isBalanced(root);
    return 0;
}

