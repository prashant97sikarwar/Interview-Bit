//Problem Link:- https://www.interviewbit.com/problems/chain-of-pairs/

#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int> > &pairs){
    int n = pairs.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if (pairs[i][0] > pairs[j][1]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res = max(res,dp[i]);
    }
    return res;
}
