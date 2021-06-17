//Problem Link:- https://www.interviewbit.com/problems/longest-arithmetic-progression/

#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int> &nums){
    int n = nums.size();
    if (n <= 2){
        return n;
    }
    vector<unordered_map<int,int>> dp(n);
    int mx = 2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = nums[j] - nums[i];
            if (dp[i].find(diff) != dp[i].end()){
                dp[j][diff] = 1 + dp[i][diff];
            }
            else{
                dp[j][diff] = 2;
            }
            mx = max(mx,dp[j][diff]);
        }
    }
    return mx;
}
