#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, vector<int> &vis,vector<int> adj[]){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n<=connections.size()+1){
            vector<int> adj[n];
            for(int i=0;i<connections.size();i++){
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }
            vector<int> vis(n,0);
            int count=0;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    count++;
                    dfs(i,vis,adj);
                }
            }
            return count-1;
        }
        else{
            return -1;
        }
    }
};