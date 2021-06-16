//Problem Link:- https://www.interviewbit.com/problems/kingdom-war/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums) {
    int n = nums.size();
    int m = nums[0].size();
    int dp[n+2][m+2]={0};
    dp[n-1][m-1]=nums[n-1][m-1];
    int maxi=INT_MIN;
    maxi=max(dp[n-1][m-1],maxi);
    if(n ==1 && m == 1) return nums[0][0];
    for(int i=n-2;i>=0;i--){
        
        dp[i][m-1]=dp[i+1][m-1]+nums[i][m-1];
        maxi=max(maxi,dp[i][m-1]);
        
    }
    for(int i=m-2;i>=0;i--){
        
        dp[n-1][i]=dp[n-1][i+1]+nums[n-1][i];
        maxi=max(maxi,dp[n-1][i]);
    }
    for(int i=n-2;i>=0;i--){
         for(int j=m-2;j>=0;j--){
            dp[i][j]=dp[i][j+1]+nums[i][j]+dp[i+1][j]-dp[i+1][j+1];    
    
             maxi=max(maxi,dp[i][j]);
           
         }   
    
    }
    
    return maxi;
}
