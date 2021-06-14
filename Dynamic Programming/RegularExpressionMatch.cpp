//Problem Link:- https://www.interviewbit.com/problems/regular-expression-match/

#include<bits/stdc++.h>
using namespace std;

int isMatch(const string s1, const string s2){
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<s1.length();i++){
        if (s1[i] != '*'){
            cnt1++;
        }
    }
    for(int i=0;i<s2.length();i++){
        if (s2[i] != '*'){
            cnt2++;
        }
    }
    if (cnt2 > cnt1){
        return 0;
    }
    int n = s1.length(), m = s2.length();
    vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
    dp[0][0] = true;
    for(int i=1;i<=m;i++){
        if (s2[i-1] == '*'){
            dp[0][i] = dp[0][i-1];
        }
        else{
            dp[0][i] = false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else if (s2[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else if (s2[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return (dp[n][m] == true ? 1 : 0);
}
