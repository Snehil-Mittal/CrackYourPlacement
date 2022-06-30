#include<vector>
using namespace std;

class Solution {
public:
    int minPathSumHelp(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0|| j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int top=grid[i][j]+minPathSumHelp(grid,i-1,j,dp);
        int left=grid[i][j]+minPathSumHelp(grid,i,j-1,dp);
        return dp[i][j]=min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return minPathSumHelp(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};