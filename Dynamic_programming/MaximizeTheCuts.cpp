#include<vector>
#include<iostream>
using namespace std;

class Solution
{
    public:
    int maximizeTheCutsHelp(int n,vector<int> &lengths,int index){
        if(index==0){
            if(n%lengths[index]==0) return n/lengths[index];
        else return INT_MIN;
        }
        if(n==0){
            return 0;
        }
        int notTake = 0 + maximizeTheCutsHelp(n,lengths,index-1);
        int Take=INT_MIN;
        if(lengths[index]<=n){
            Take = 1+maximizeTheCutsHelp(n-lengths[index],lengths,index);
        }
        return max(Take,notTake);
        
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> lengths;
        lengths.push_back(x);
        lengths.push_back(y);
        lengths.push_back(z);
        
        int result = maximizeTheCutsHelp(n,lengths,lengths.size()-1);
        if(result < 0) return 0;
        else return result;
    }
};