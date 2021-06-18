//Problem Link:- https://www.interviewbit.com/old/problems/n-digit-numbers-with-digit-sum-s-/

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int mod = 1000000007;

long long helper(int n, int x)
{
    if(n == 0 && x == 0) return 1;
    if(n == 0 || x == 0) return 0;
    
    if(dp[n][x] != -1) return dp[n][x];
    
    long long ans = 0;
    for(int i = 0; i <= min(x,9); i++)
    {
        ans = (ans % mod) + (helper(n-1, x-i) % mod);
    }
    return dp[n][x] = ans % mod;
}
int solve(int A, int B) 
{
    memset(dp, -1, sizeof(dp));
    return helper(A, B);
}