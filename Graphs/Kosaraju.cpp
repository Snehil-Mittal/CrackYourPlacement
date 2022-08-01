#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int i,stack<int> &s,vector<int> &vis,vector<int> adj[]){
	    vis[i]=1;
	    for(auto j: adj[i]){
	        if(!vis[j]){
	            dfs(j,s,vis,adj);
	        }
	    }
	    s.push(i);
	}
	void revdfs(int i, vector<int> &vis,vector<int> trans[]){
	    vis[i]=1;
	     for(auto j: trans[i]){
	        if(!vis[j]){
	            revdfs(j,vis,trans);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,s,vis,adj);
            }
        }
        
        vector<int> trans[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto j: adj[i]){
                trans[j].push_back(i);
            }
        }
        int count=0;
        while(!s.empty()){
            int i=s.top();
            s.pop();
            if(!vis[i]){
                count++;
                revdfs(i,vis,trans);
            }
        }
        return count;
    }
};
