//Problem LinK:- https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

#include<bits/stdc++.h>
using namespace std;

int adjacent(vector<vector<int> > &nums){
    if (nums[0].size() == 1){
        return max(nums[0][0], nums[1][0]);
    }
    int n = nums[0].size();
    vector<int> dp(n,0);
    dp[n-1] = max(nums[0][n-1], nums[1][n-1]);
    for(int i=n-2;i>=0;i--){
        if (i+2 >= n){
            dp[i] = max(dp[i+1], max(nums[0][i], nums[1][i]));
        }
        else{
            dp[i] = max(dp[i+1], dp[i+2] + max(nums[0][i], nums[1][i]));
        }
    }
    return dp[0];
}
