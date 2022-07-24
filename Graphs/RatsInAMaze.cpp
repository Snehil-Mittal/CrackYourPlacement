#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void paths(int i,int j,vector<vector<int>> &m,vector<string> &result,string temp){
        if(i==0 && j==0 && m[i][j]==1){
            result.push_back(temp);
            return;
        }
        if(i<0 || j<0 || i>=m.size() || j>=m.size()){
            return;
        }
        if(m[i][j]==1){
            m[i][j]=0;
            paths(i-1,j,m,result,temp+'D');
            paths(i,j-1,m,result,temp+'R');
            paths(i+1,j,m,result,temp+'U');
            paths(i,j+1,m,result,temp+'L');
            m[i][j]=1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result,fresult; string temp="";
        paths(n-1,n-1,m,result,temp);
        for(auto i:result){
            string temp=i;
            reverse(temp.begin(),temp.end());
            fresult.push_back(temp);
        }
        return fresult;
    }
};