#include<vector>
using namespace std;
class Solution {
public:
    int CoinChangeHelp(vector<int>&coins,int amount,int index,vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            else return 1e9;
        }
        if(amount==0){
            return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int NotTake= 0 + CoinChangeHelp(coins,amount,index-1,dp);
        
        int Take=1e9; 
        if(coins[index]<=amount){
            Take = 1 + CoinChangeHelp(coins,amount-coins[index],index,dp);
        }
       
        return dp[index][amount]=min(Take,NotTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int result = CoinChangeHelp(coins,amount,coins.size()-1,dp);
        if (result==1e9) return -1;
        else return result;
    }
};  