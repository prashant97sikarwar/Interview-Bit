//Problem Link:- https://www.interviewbit.com/problems/0-1-knapsack/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &val, vector<int> &wt, int W){
    int n = wt.size();
    if (n == 1){
        if (wt[0] <= W){
            return val[0];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=W;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if (j >= wt[i-1]){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
