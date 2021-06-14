//Problem Link:- https://www.interviewbit.com/problems/ways-to-decode/

#include<bits/stdc++.h>
using namespace std;

long long dp[100005];
const long long mod = 1e9 + 7;

int helper(string s, long long i){
    if (i == s.length()){
        return 1;
    }
    if (dp[i] != -1){
        return dp[i];
    }
    long long res = 0;
    if (s[i] > '0'){
        res += helper(s,i+1)%mod;
        res %= mod;
    }
    if (i < s.length()-1 && (s[i] == '1' || (s[i] == '2' &&  s[i+1] <= '6'))){
        res += helper(s,i+2)%mod;
        res %= mod;
    }
    return dp[i] = res%mod;
}

int numDecodings(string s){
    memset(dp,-1,sizeof(dp));
    return helper(s,0)%mod;
}
