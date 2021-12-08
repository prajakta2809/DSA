#include<bits/stdc++.h>
using namespace std;

void solve(int once,int zeros,string op,vector<string>&v,int n){
	if(n==0){
		v.push_back(op);
		return;
	}
	string op1=op;
	op1.push_back('1');
	solve(once+1,zeros,op1,v,n-1);
	if(once>zeros){
	
		string op2=op;
		op2.push_back('0');
		solve(once,zeros+1,op2,v,n-1);
	}

}


int main(){
	int n;
	cin>>n;
	vector<string>v;
	string op="";
	solve(0,0,op,v,n);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";
		
	}
	return 0;
}
