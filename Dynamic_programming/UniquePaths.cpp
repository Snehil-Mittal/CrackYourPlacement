#include<vector>
using namespace std;
class Solution {
public:
 
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0),cur(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) cur[j]=1;
                else{
                      int top=0;
                      if((i-1)>=0) top = prev[j];
                      int left=0;
                      if((j-1)>=0) left = cur[j-1];
                      cur[j] = top+left;
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};