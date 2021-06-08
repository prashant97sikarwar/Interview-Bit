//Problem Link:- https://www.interviewbit.com/problems/flip-array/

#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int> &nums){
    int n = nums.size();
    int sm = 0;
    for(int i=0;i<n;i++){
        sm += nums[i];
    }
    sm /= 2;
    vector<vector<int>> dp(n+1,vector<int>(sm+1,INT_MAX-2));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sm;j++){
            if (j >= nums[i-1]){
                dp[i][j] = min(1 + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if (dp[n][sm] == INT_MAX-2){
        int i = sm;
        for(i=sm;i>=0;i--){
            if (dp[n][i] < INT_MAX-2){
                return dp[n][i];
            }
        }
    }
    return dp[n][sm];
}
