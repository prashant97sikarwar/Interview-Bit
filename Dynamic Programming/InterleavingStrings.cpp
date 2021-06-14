//Problem Link:- https://www.interviewbit.com/problems/interleaving-strings/

#include<bits/stdc++.h>
using namespace std;

int dp[151][151];

int helper(int i,string s1, int j,string s2, int k, string s3){
    if (i == s1.length()){
        if (s2.substr(j).compare(s3.substr(k)) == 0){
            return dp[i][j] = 1;
        }
        else{
            return dp[i][j] = 0;
        }
    }
    if (j == s2.length()){
        if (s1.substr(i).compare(s3.substr(k)) == 0){
            return dp[i][j] = 1;
        }
        else{
            return dp[i][j] = 0;
        }
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    bool ans = false;
    if (s1[i] == s3[k] && helper(i+1,s1,j,s2,k+1,s3) || s2[j] == s3[k] && helper(i,s1,j+1,s2,k+1,s3)){
        ans = true;
    }
    dp[i][j] = (ans == false ? 0 : 1);
    return dp[i][j];
}

int isInterleave(string s1, string s2, string s3){
    if (s1.length() + s2.length() != s3.length()){
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    return helper(0,s1,0,s2,0,s3);
}
