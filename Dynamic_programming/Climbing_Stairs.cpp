#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int>dp;
    int climbStairs(int n) {
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
            
    }
};
vector<int> Solution::dp(47,-1);