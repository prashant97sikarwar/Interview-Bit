//problem Link:- https://www.interviewbit.com/problems/palindrome-partitioning-ii/

#include<bits/stdc++.h>
using namespace std;

int minCut(string s){
    int len = s.length();
    vector<int>dp(len+1,0);
    vector<vector<bool>> isPal(len+1,vector<bool> (len+1,false));
    for(int i=0;i<=len;i++){
        isPal[i][i] = true;
    }
    for(int l=2;l<=len;l++){
        for(int start=0;start<len-l+1;start++){
            int end = start + l -1;
            if (l == 2)
                isPal[start][end] = (s[start] == s[end]);
            else{
                isPal[start][end] = (s[start] == s[end] && isPal[start+1][end-1]);
            }
        }
    }
    for(int i=0;i<len;i++){
        if (isPal[0][i])
            dp[i] = 0;
        else{
            dp[i] = INT_MAX;
            for(int j=0;j<i;j++){
                if (isPal[j+1][i] && 1 + dp[j] < dp[i])
                    dp[i] = 1 + dp[j];
            }
        }
    }
    return dp[len-1];
}