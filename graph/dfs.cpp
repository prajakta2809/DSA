#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,int V){
	cout<<node<<" ";
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis,V);
		}
	}
}

int main(){
		int n,e;
	cout<<"Enter number of vertex: "<<endl;
	cin>>n;
	cout<<"Enter number of Edges: "<<endl;
	cin>>e;
	int x,y;
	vector<int>adj[n+1];
	cout<<"Enter edges: ";
	for(int i=1;i<=n;i++){
	    	cout<<"Enter edges: ";
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		dfs(i,adj,vis,n);
		}
	}

	return 0;
}
