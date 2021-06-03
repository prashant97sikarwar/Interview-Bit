//Problem Link:- https://www.interviewbit.com/problems/increasing-path-in-matrix/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
    dp[0][0]=1;
    for(int j=1;j<m;j++){
        if(dp[0][j-1]==INT_MIN) continue;
        dp[0][j]=A[0][j]>A[0][j-1]?dp[0][j-1]+1:INT_MIN;
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][0]==INT_MIN) continue;
        dp[i][0]=A[i][0]>A[i-1][0]?dp[i-1][0]+1:INT_MIN;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][j]>A[i][j-1]){
                if(dp[i][j-1]!=INT_MIN)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
            }
            if(A[i][j]>A[i-1][j]){
                if(dp[i-1][j]!=INT_MIN)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
            }
        }
    }
    return dp[n-1][m-1]==INT_MIN?-1:dp[n-1][m-1];
}