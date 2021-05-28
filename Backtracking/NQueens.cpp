//Problem Link:- https://www.interviewbit.com/problems/nqueens/

#include<bits/stdc++.h>
using namespace std;

bool valid(vector<string> board,int row, int col){
    for(int i=row;i>=0;i--){
        if (board[i][col] == 'Q')
            return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if (board[i][j] == 'Q')
            return false;
    }
    for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void helper(vector<string>& board,vector<vector<string>> &result, int n,int row){
    if (row >= n){
        result.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if (valid(board,row,col)){
            board[row][col] = 'Q';
            helper(board,result,n,row+1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> result;
    vector<string> board(n,string(n,'.'));
    helper(board,result,n,0);
    return result;
}