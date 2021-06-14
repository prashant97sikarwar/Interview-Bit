//Problem Link:- https://www.interviewbit.com/problems/arrange-ii/

#include<bits/stdc++.h>
using namespace std;

int helper(string s,int k,int i,vector<vector<int>>& dp){
    if (i >= s.length()){
        return 1e9;
    }
    if (dp[i][k] != 1e9){
        return dp[i][k];
    }
    int black = 0,white = 0, ans = INT_MAX;
    if (k == 1){
        for(int idx=i;idx<s.length();idx++){
            if (s[idx] == 'W'){
                white++;
            }
            else{
                black++;
            }
        }
        return dp[i][k] = black*white;
    }
    for(int idx=i;idx<=s.length()-k;idx++){
        if (s[idx] == 'W'){
            white++;
        }
        else{
            black++;
        }
        ans = min(ans,white*black + helper(s,k-1,idx+1,dp));
    }
    return dp[i][k] = ans;
}

int arrange(string s, int k){
    int n = s.length();
    if (n < k){
        return -1;
    }
    vector<vector<int>> dp(n+1,vector<int> (k+1,1e9));
    return helper(s,k,0,dp);
}
