#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void dfs(int i, stack<int> &s, vector<int> &vis,vector<int> adj[]){
	    vis[i]=1;
	    for(auto j:adj[i]){
	        if(!vis[j]){
	            dfs(j,s,vis,adj);
	        }
	    }
	    s.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,s,vis,adj);
	        }
	    }
	    vector<int> result;
	    while(!s.empty()){
	        result.push_back(s.top());
	        s.pop();
	    }
	    return result;
	}
};


