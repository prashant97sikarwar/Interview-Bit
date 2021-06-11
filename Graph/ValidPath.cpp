//Problem Link:- https://www.interviewbit.com/problems/valid-path/

#include<bits/stdc++.h>
using namespace std;

bool valid(int i,int j,int tx,int ty,vector<vector<bool>>& visited,vector<vector<int>>& grid){
    if (i >= 0 && j >= 0 && i <= tx && j <= ty && grid[i][j] == 0 && visited[i][j] == false){
        return true;
    }
    return false;
}

void dfs(int tx,int ty,int sx,int sy,vector<vector<int>>& grid,vector<vector<bool>>& visited){
    visited[sx][sy] = true;
    int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1};
    for(int k=0;k<8;k++){
        if (valid(sx+dx[k],sy+dy[k],tx,ty,visited,grid)){
            dfs(tx,ty,sx+dx[k],sy+dy[k],grid,visited);
        }
    }
    
}

string solve(int x, int y, int n, int r, vector<int> &A, vector<int> &B){
    vector<vector<int>> grid(x+1,vector<int> (y+1,0));
    vector<vector<bool>> visited(x+1,vector<bool> (y+1,false));
    
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            for(int k = 0; k < n; k++){
                if(sqrt(pow(A[k]-i,2)+pow(B[k]-j,2)) <= r){
                    grid[i][j] = 1;
                    break;
                }
            }
        }
    }
    if (grid[0][0] == 1 ||  grid[x][y] == 1){
        return "NO";
    }
    dfs(x,y,0,0,grid,visited);
    if (visited[x][y] == true){
        return "YES";
    }
    return "NO";
}
