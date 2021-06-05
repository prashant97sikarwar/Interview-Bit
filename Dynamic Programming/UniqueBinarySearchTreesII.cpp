//Problem Link:- https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int numTrees(int n){
    if (n == 0){
        return 0;
    }
    vector<ll> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = 0;
        for(int j=0;j<i;j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}