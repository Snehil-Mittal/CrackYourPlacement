#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfitHelp(int ind,int trans,vector<int>&prices,vector<vector<int>> &dp){
        if(ind==prices.size() || trans==2) return 0;
        int profit= INT_MIN;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0){
            profit=max(-prices[ind]+maxProfitHelp(ind+1,trans+1,prices,dp),0+maxProfitHelp(ind+1,trans,prices,dp));
        }
        else{
            profit=max(prices[ind]+maxProfitHelp(ind+1,trans+1,prices,dp),0+maxProfitHelp(ind+1,trans,prices,dp));
        }
        return dp[ind][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return maxProfitHelp(0,0,prices,dp);
    }
};