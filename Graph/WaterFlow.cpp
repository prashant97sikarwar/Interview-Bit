//Problem Link:- https://www.interviewbit.com/old/problems/water-flow/

#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i,int j,set<pair<int,int>>& vis,vector<vector<int>>& mat,int prev){
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || vis.count({i,j}) || mat[i][j] < prev){
        return;
    }
    vis.insert({i,j});
    for(int k=0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        dfs(nx,ny,vis,mat,mat[i][j]);
    }
}


int solve(vector<vector<int> > &mat){
    int rows = mat.size();
    int cols = mat[0].size();
    set<pair<int,int>> blue;
    set<pair<int,int>> red;
    
    for(int c=0;c<cols;c++){
        dfs(0,c,blue,mat,mat[0][c]);
        dfs(rows-1,c,red,mat,mat[rows-1][c]);
    }
    
    for(int r=0;r<rows;r++){
        dfs(r,0,blue,mat,mat[r][0]);
        dfs(r,cols-1,red,mat,mat[r][cols-1]);
    }
    
    int res = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (blue.count({i,j}) && red.count({i,j})){
                res++;
            }
        }
    }
    return res;
}
