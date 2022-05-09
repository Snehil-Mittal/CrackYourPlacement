#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSafe(vector<vector<char>> &board,int row ,int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            
            if(board[row][i]==c) return false;
            
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool solveSudokuHelp(vector<vector<char>> &board,int i,int j){
        if(j==9)
        {
            i++;
            j=0;
        }
        if(i==9)
            return true;
        
        if(board[i][j]=='.'){
            for(char c='1';c<='9';c++)
            {
                if(isSafe(board,i,j,c)){
                    board[i][j]=c;
                    if(solveSudokuHelp(board,i,j+1)){
                        return true;
                    }
                    else{
                        board[i][j]='.';
                    }
                    
                 }
            }
            return false;
            
        }
        if(solveSudokuHelp(board,i,j+1))
            return true;
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelp(board,0,0);
    }
};