//Problem Link:- https://www.interviewbit.com/old/problems/region-in-binarymatrix/

#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int i,int j,int n,int m,vector<vector<int> > &mat,int &cnt){
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 1){
        return;
    }
    cnt++;
    mat[i][j] = 0;
    for(int k=0;k<8;k++){
        int nr = i + dx[k];
        int ny = j + dy[k];
        dfs(nr,ny,n,m,mat,cnt);
    }
}

int solve(vector<vector<int> > &mat){
    const int n = mat.size();
    const int m = mat[0].size();
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (mat[i][j] == 1){
                int cnt = 0;
                dfs(i,j,n,m,mat,cnt);
                result = max(result,cnt);
            }
        }
    }
    return result;
}
