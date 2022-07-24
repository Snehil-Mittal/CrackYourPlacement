#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(int i,vector<int> &result,vector<int> &vis,vector<int> adj[]){
     queue<int> q;
     vis[i]=1;
     q.push(i);
     while(!q.empty()){
         result.push_back(q.front());
         int temp=q.front();
         q.pop();
         for(auto j: adj[temp]){
             if(!vis[j]){
                 q.push(j);
                 vis[j]=1;
             }
         }
     }
     return result;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> result;
        bfs(0,result,vis,adj);
        return result;
    }
};
