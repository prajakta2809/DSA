#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[],int V){
	

	vector<int>vis(V+1,0);
	for(int i=1;i<=V;i++){
		if(!vis[i]){
			queue<int>q;
			q.push(i);
			vis[i]=1;
			while(!q.empty()){
				int node=q.front();
				q.pop();
			
				cout<<node<<" ";
				for(auto it :adj[node]){
					if(!vis[it]){
						q.push(it);
						vis[it]=1;
					}
				}
			}
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
     bfs(adj,n);

	
	
	return 0;
}
