#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfitHelp(int ind,int buy,vector<int>&prices,vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        int profit= INT_MIN;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(-prices[ind]+maxProfitHelp(ind+1,0,prices,dp),0+maxProfitHelp(ind+1,1,prices,dp));
        }
        else{
            profit=max(prices[ind]+maxProfitHelp(ind+1,1,prices,dp),0+maxProfitHelp(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return maxProfitHelp(0,1,prices,dp);
    }
};