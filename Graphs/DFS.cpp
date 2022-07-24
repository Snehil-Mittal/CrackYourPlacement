#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dfs(int i,vector<int> &result,vector<int> &vis,vector<int> adj[]){
     result.push_back(i);
     vis[i]=1;
     for(auto j: adj[i]){
             if(!vis[j]){
                dfs(j,result,vis,adj);
             }
      }
     return result;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> result;
        dfs(0,result,vis,adj);
        return result;
    }
};
