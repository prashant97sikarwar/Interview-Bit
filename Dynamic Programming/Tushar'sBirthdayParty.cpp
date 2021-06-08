//Problem Link:- https://www.interviewbit.com/problems/tushars-birthday-party/ 

#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C){
    long long na = A.size();
    long long nb = B.size();
    long long nc = C.size();
    long long mx = *max_element(A.begin(), A.end());
    vector<vector<long long>> dp(nb+1,vector<long long> (mx+1, INT_MAX-2));
    for(long long i=0;i<=nb;i++){
        dp[i][0] = 0;
    }
    for(long long i=1;i<=mx;i++){
        if (i % B[0] == 0){
            dp[1][i] = (i/B[0])*C[0];
        }
    }
    for(long long i=2;i<=nb;i++){
        for(long long j=1;j<=mx;j++){
            if (j >= B[i-1]){
                dp[i][j] = min(dp[i-1][j], min(C[i-1] + dp[i-1][j-B[i-1]], C[i-1] + dp[i][j-B[i-1]]));
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res = 0;
    for(int i=0;i<na;i++){
        res += dp[nb][A[i]];
    }
    return res;
}
