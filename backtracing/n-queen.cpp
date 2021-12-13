// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

   bool isValid(int i,int j,vector<vector<int>>&board,int &n){
       int row=i-1,col=j;
       while(row>=0 && col>=0 && row<n && col<n){
           if(board[row][col] !=0){
               return false;
           }
           row--;
       }
       row=i-1,col=j-1;
       while(row>=0 && col>=0 && row<n && col<n){
           if(board[row][col] !=0){
               return false;
           }
           row--;col--;
       }
       row=i-1,col=j+1;
       
       while(row>=0 && col>=0 && row<n && col<n){
           if(board[row][col] !=0){
               return false;
           }
           row--;col++;
       }
       return true;
   }
    void solve(int row,vector<int>&temp,vector<vector<int>>&board,vector<vector<int>>&ans,int &n){
       if(row==n){
           ans.push_back(temp);
           return;
       }        
       for(int j=0;j<n;j++){
           if(isValid(row,j,board,n)){
               temp.push_back(j+1);
               board[row][j]=1;
               solve(row+1,temp,board,ans,n);
               board[row][j]=0;
               temp.pop_back();
           }
       }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>temp;
        solve(0,temp,board,ans,n);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
