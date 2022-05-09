#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSafe(int row,int col,vector<string> &Board){
        int r=row;
        while(r>=0){
            if(Board[r][col]=='Q')
                return false;
            r--;
        }
        
        int c=col;
        while(c>=0){
            if(Board[row][c]=='Q'){
                return false;
            }
            c--;
        }
        
        r=row;
        c=col;
        while(r>=0 && c>=0){
            if(Board[r][c]=='Q')
                return false;
            c--;
            r--;
        }
        
        r=row;
        c=col;
        while(r>=0 && c<Board.size()){
            if(Board[r][c]=='Q')
                return false;
            c++;
            r--;
        }
        
        return true;
        
    }
    void solveQueensHelp(int row,int col,int qp, int n, vector<vector<string>> &result,vector<string> &Board){
        if(qp==n){
            result.push_back(Board);
            return;
        }
        if(col==n){
            row++;
            col=0;
        }
        if(row==n){
            return;
        }
        if(isSafe(row,col,Board)){
            Board[row][col]='Q';
            solveQueensHelp(row,col+1,qp+1,n,result,Board);
            Board[row][col]='.';
        }
        solveQueensHelp(row,col+1,qp,n,result,Board);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> Board(n);
        string s;
        s.append(n,'.');
        for(int i=0;i<n;i++){
            Board[i]=s;
        }
        solveQueensHelp(0,0,0,n,result,Board);
        return result;
    }
};