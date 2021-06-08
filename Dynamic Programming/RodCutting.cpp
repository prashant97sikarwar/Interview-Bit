//Problem Link:- https://www.interviewbit.com/problems/rod-cutting/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&cuts,int i,int j, vector<vector<int>>& dp, vector<vector<int>>& part){
    if (j-i <= 1){
        dp[i][j] = 0;
        part[i][j] = -1;
        return dp[i][j];
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    int idx;
    for(int k=i+1;k<j;k++){
        int temp = helper(cuts,i,k,dp,part)  + helper(cuts,k,j,dp,part) + (cuts[j] - cuts[i]);
        if (temp < ans){
            ans = temp;
            idx = k;
        }
    }
    if (ans != INT_MAX){
        dp[i][j] = ans;
        part[i][j] = idx;   
    }
    else{
        dp[i][j] = 0;
        part[i][j] = -1;
    }
    return dp[i][j];
}

void build(vector<int>& result,int start, int end, vector<int>& cuts, vector<vector<int>> &part){
    if (part[start][end] == -1){
        return;
    }
    else{
        result.push_back(cuts[part[start][end]]);
        build(result,start,part[start][end],cuts,part);
        build(result,part[start][end],end,cuts,part);
    }
}

vector<int> rodCut(int n, vector<int> &cuts){
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.insert(cuts.end(),n);
    int sz = cuts.size();
    vector<vector<int>> dp(sz+1,vector<int> (sz+1,-1));
    vector<vector<int>> part(sz+1,vector<int> (sz+1,0));
    vector<int> result;
    helper(cuts,0,cuts.size()-1,dp,part);
    build(result,0,cuts.size()-1,cuts,part);
    return result;
}
