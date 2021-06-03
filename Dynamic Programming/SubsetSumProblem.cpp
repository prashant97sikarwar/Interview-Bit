//Problem Link:- https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target){
    int n = nums.size();
    if (n == 1 && nums[0] == target){
        return 1;
    }
    vector<vector<int>> dp(n+1,vector<int> (target+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if (j >= nums[i-1]){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}
