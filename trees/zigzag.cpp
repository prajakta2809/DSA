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

/*Zig zag traversal*/
vector<vector<int>>zigzag(node* root){
    queue<node*>q;
    vector<vector<int>>res;
    if(root==NULL){
        return res;
        
    }
    bool LtoR=true;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
           node* temp=q.front();
           q.pop();
           
           int index=LtoR?i:size-1-i;
           
           row[index]=temp->data;
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
        }
        LtoR = !LtoR;
        res.push_back(row);
       
    }
    return res;
} 

int main(){
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    vector<vector<int>>ans=zigzag(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
