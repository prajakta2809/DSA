#include <bits/stdc++.h>

using namespace std;

bool isCheck(vector<int>adj[],int src,vector<int>&color){
    queue<int>q;
    color[src]=1;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
    
}


bool bipartate(vector<int>adj[],int n){
    vector<int>color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!isCheck(adj,i,color)){
                return false;
            }
        }
    }
    return true;
}

int main()
{
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
	if(bipartate(adj,n)){
	    cout<<"true";
	}
	else{
	    cout<<"false";
	}
}

