// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:vector<string>ans;
    
    void solve(vector<vector<int>> &m, int n, int r,int c , string op){
         if(r <0 || c < 0 || r >= n || c >= n || m[r][c] == 0)
       {
           return ;
       }
       
        if(r == n-1 && c == n-1)
       {
           ans.push_back(op);
       }
       
       m[r][c] = 0;
        solve(m,n,r+1,c,op+"D" );
        solve(m,n,r,c+1,op+"R" );
       solve(m,n,r-1,c,op+"U" );
       solve(m,n,r,c-1,op+"L" );
       m[r][c] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return ans;
        }
        solve(m,n,0,0,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
