//Problem Link:- https://www.interviewbit.com/problems/minimum-difference-subsets/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n = nums.size();
    if (n == 1){
        return nums[0];
    }
    int sm = 0;
    for(int i=0;i<nums.size();i++){
        sm += nums[i];
    }
    vector<vector<int>> dp(n+1,vector<int> (sm/2+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sm/2;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sm/2;j++){
            if (j >= nums[i-1]){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int i = sm/2;
    for(;i>=0;i--){
        if (dp[n][i] == 1){
            break;
        }
    }
    return sm - 2*i;
}
