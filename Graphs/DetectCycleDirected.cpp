#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkCycle(int i,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[]){
        vis[i]=true;
        dfsVis[i]=true;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(checkCycle(j,vis,dfsVis,adj))
                    return true;
            }else if(dfsVis[j]){
                return true;
            }
        }
        dfsVis[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,dfsVis,adj))
                    return true;
            }
        }
        return false;
    }
};
