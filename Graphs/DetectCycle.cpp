#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool checkCycle(int i,int parent, vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(checkCycle(j,i,adj,vis))
                    return true;
            }
            else if(j!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,-1,adj,vis))
                 return true;
            }
        }
        return false;
    }
};