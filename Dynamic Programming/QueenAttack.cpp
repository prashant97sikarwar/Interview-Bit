//Problem Link:- https://www.interviewbit.com/problems/queen-attack/

#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int y, int n,int m,vector<vector<int>> &dp,vector<string> &mat,int xs,int ys){
    if (x < 0 || y < 0 || x >= n || y >= m){
        return;
    }
    dp[x][y]++;
    if (mat[x][y] == '0'){
        dfs(x+xs,y+ys,n,m,dp,mat,xs,ys);
    }
}

vector<vector<int> > queenAttack(vector<string> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    int dx[] = {-1,-1,0,1,1,1,0,-1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (mat[i][j] == '1'){
                for(int k=0;k<8;k++){
                    dfs(i+dx[k],j+dy[k],n,m,dp,mat,dx[k],dy[k]);
                }
            }
        }
    }
    return dp;
}
