#include<bits/stdc++.h>
using namespace std;

void UndirectedBfs(vector<int>adj[],int src,int V){
	queue<int>q;
	vector<int>dis(V,INT_MAX);
	dis[src]=0;
	q.push(src);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto it: adj[node]){
			if(dis[node]+1<dis[it]){
				dis[it]=dis[node]+1;
				q.push(it);
			}
		}
	}
	for(int i=0;i<dis.size();i++){
		cout<<dis[i]<<" ";
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
	for(int i=1;i<=e;i++){
	    	cout<<"Enter edges: ";
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	UndirectedBfs(adj,0,n);
	return 0;
}
