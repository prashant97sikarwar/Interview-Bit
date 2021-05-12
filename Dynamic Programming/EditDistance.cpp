//Problem Link:- https://www.interviewbit.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;

int minDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if (i == 0){
                dp[i][j] = j;
            }
            else if (j == 0){
                dp[i][j] = i;
            }
            else if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int f = 1 + dp[i][j-1];
                int s = 1 + dp[i-1][j-1];
                int t = 1 + dp[i-1][j];
                dp[i][j] = min(f,min(s,t));
            }
        }
    }
    return dp[n][m];
}
