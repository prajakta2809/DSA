#include<bits.stdc++.h>
using namepsace std;

void Sortdfs(int node,vector<int>adj,vector<int>&vis,stack<int>&st){
	vis[node]=1;
	
		for(auto it:adj[node]){
			if(!vis[it]){
				Sortdfs(it,adj,vis,st);
			}
		}
	st.push(node);
	
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
	stack<int>st;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		Sortdfs(i,adj,vis,st);
		}
	}
	
	vector<int>ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
