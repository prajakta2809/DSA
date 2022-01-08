
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
//Diameter of tree: longest path between two nodes;need not to be pass throung root
int Diameter(node* root,int maxi){
    if(root==NULL){
        return 0;
    }
    int l=Diameter(root->left,maxi);
    int r=Diameter(root->right,maxi);
    maxi=max(maxi,l+r);
    return 1+max(l,r);
    
}
//Maximum path sum
 int MaxpathSum(node* root,int &sum){
    if(root==NULL){
        return 0;
    }
    int l=max(0,MaxpathSum(root->left,sum));
    int r=max(0,MaxpathSum(root->right,sum));
    sum=max(sum,l+r+root->data);
    return max(l,r)+root->data;
    
 }
int main()
{
   struct node* root=new node(1);
   root->left=new node(2);
   root->right=new node(3);
   root->left->left=new node(4);
   root->right->right=new node(5);
   cout << Diameter(root,0); 
   int min=INT_MIN;
   cout<<endl;
   cout<<MaxpathSum(root,min);
    return 0;
}

