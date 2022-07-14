#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfitHelp(int ind,int trans,int k,vector<int>&prices,vector<vector<int>> &dp){
        if(ind==prices.size() || trans== 2*k) return 0;
        int profit= INT_MIN;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0){
            profit=max(-prices[ind]+maxProfitHelp(ind+1,trans+1,k,prices,dp),0+maxProfitHelp(ind+1,trans,k,prices,dp));
        }
        else{
            profit=max(prices[ind]+maxProfitHelp(ind+1,trans+1,k,prices,dp),0+maxProfitHelp(ind+1,trans,k,prices,dp));
        }
        return dp[ind][trans]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k,-1));
        return maxProfitHelp(0,0,k,prices,dp);
    }
};