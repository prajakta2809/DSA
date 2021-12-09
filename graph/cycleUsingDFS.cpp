#include<bits/stdc++.h>
using namespace std;
//tc: O(n+e)
//sc: O(n+e)+O(n)+O(n)

bool isCycle(vector<int>adj[],vector<int>&vis,int node,int parent){
	vis[node]=1;
	for(auto it:adj[node]){
		if(vis[it]==0){
			if(isCycle(adj,vis,it,node)){
				return true;
			}
		}
		else if(it!=parent){
			return true;
		}
	}
	return false;
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
	for(int i=1;i<=e;i++){
	    	cout<<"Enter edges: ";
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>vis(n+1,0);
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(isCycle(adj,vis,i,-1)){
				flag=true;
			}
		}
	}
	cout<<flag;
	
	return 0;
}
