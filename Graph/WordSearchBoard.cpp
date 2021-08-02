//Problem Link:- https://www.interviewbit.com/old/problems/word-search-board/

#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

bool dfs(int i, int j,int idx,int n,int m,vector<string> &A,string& B){
    if (idx >= B.length()){
        return true;
    }
    if (i < 0 || j < 0 || i >= n || j >= m || A[i][j] != B[idx]){
        return false;
    }
    bool flag = 0;
    for(int k=0;k<4;k++){
        flag = flag || dfs(i+dx[k],j+dy[k],idx+1,n,m,A,B);
    }
    return flag;
}

int exist(vector<string> &A, string B) {
    const int n = A.size();
    const int m = A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (A[i][j] == B[0] && dfs(i,j,0,n,m,A,B)){
                return true;
            }
        }
    }
    return false;
}
