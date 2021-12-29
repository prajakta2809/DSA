

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

void preorder(node* root){
     vector<int>ans;
    if(root==NULL){
        return ;
    }
   
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        cout<<root->data;
        st.pop();
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }
}

void inorder(node* root){
    stack<node*>st;
    node* temp=root;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()==true)
             break;
            temp=st.top();
            st.pop();
            cout<<temp->data;
            temp=temp->right;
        }
    }
}
/* All traversal using 1 stack*/

void PostInPre(node* root){
    stack<pair<node*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    if(root==NULL){
        return;
    }
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->left !=NULL){
                st.push({it.first->left,1});
            }
        }
        if(it.second==2){
            post.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right !=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
}

/* End*/


int main(){
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    preorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}

