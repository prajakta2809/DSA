
//tc: O(n+e)
//sc: O(n+e)+O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>adj[],vector<int>&vis,int s){
	queue<pair<int,int>>q;
	vis[s]=1;
	q.push({s,-1});
	while(!q.empty()){
		int node=q.front().first;
		int par=q.front().second;
		q.pop();
		for(auto it: adj[node]){
			if(!vis[it]){
				q.push({it,node});
				vis[it]=1;
			}
			else if(it!=par){
				return true;
			}
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
	bool flag=false;
	vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		if(isCycle(adj,vis,i)){
    			flag=true;
			}
		}
	}
	cout<<flag;

	return 0;
}
