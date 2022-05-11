#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void numIslandsHelp(vector<vector<char>> & grid, int row,int col,bool &flag){
        if(row>=0 && row<grid.size()){
            if(col>=0 && col<grid[0].size()){
                if(grid[row][col]=='1'){
                    flag=true;
                    grid[row][col]=0;
                    numIslandsHelp(grid,row,col+1,flag);
                    numIslandsHelp(grid,row+1,col,flag); 
                    numIslandsHelp(grid,row,col-1,flag); 
                    numIslandsHelp(grid,row-1,col,flag);
                    
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0; bool flag=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                numIslandsHelp(grid,i,j,flag);
                if(flag)
                  count++;
                flag=false;
            }
        }
        return count;
    }
};