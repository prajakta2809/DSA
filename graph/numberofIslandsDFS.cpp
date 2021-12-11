// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void DFS(vector<vector<char>> &A,int i,int j)
   {
       if(i==A.size() or j==A[i].size() or i<0 or j<0) // boundary conditions...
           return;
       if(A[i][j]=='0') // water...
           return;
       A[i][j]='0'; // marked as visited...
       DFS(A,i+1,j);
       DFS(A,i,j+1);
       DFS(A,i-1,j);
       DFS(A,i,j-1);
       DFS(A,i-1,j-1);
       DFS(A,i+1,j+1);
       DFS(A,i-1,j+1);
       DFS(A,i+1,j-1);
   }
    int numIslands(vector<vector<char>>& A) {
        // Code here
          auto count=0; // counter for counting the islands...
       for(int i=0;i<A.size();i++)
       {
           for(int j=0;j<A[i].size();j++)
           {
               if(A[i][j]=='0')
                   continue;
               DFS(A,i,j);
               count++;
           }
       }
       return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
