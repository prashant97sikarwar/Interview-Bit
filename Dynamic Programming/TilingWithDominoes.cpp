//Problem Link:- https://www.interviewbit.com/problems/tiling-with-dominoes/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 +7;
int solve(int n){
    if(n%2==1)
        return 0;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[2]=3;
    
    long long temp=8;
    for(int i=4;i<=n;i+=2)
    {
        dp[i] = (temp+dp[i-2])%mod;
        temp = (temp + (2*dp[i])%mod )%mod;
    }
    return dp[n];
}