//Problem Link:- https://www.interviewbit.com/problems/merge-elements/

#include<bits/stdc++.h>
using namespace std;

int dp[201][201];
int solve(vector<int> &nums) {
    int n = nums.size();
    memset(dp,0,sizeof(dp));
    vector<int> prefix(n+1,0);
    prefix[0] = 0;
    for(int i=0;i<n;i++){
        prefix[i+1] = prefix[i] + nums[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<=j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + prefix[j+1] - prefix[i]);
            }
        }
    }
    return dp[0][n-1];
}
