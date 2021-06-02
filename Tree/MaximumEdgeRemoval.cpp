//Problem Link:- https://www.interviewbit.com/problems/maximum-edge-removal/

#include<bits/stdc++.h>
using namespace std;

int helper(int &res,unordered_map<int,vector<int>>& mp,int u,int n,vector<bool> &vis){
    vis[u] = true;
    int cur = 0;
    for(int i=0;i<mp[u].size();i++){
        int v = mp[u][i];
        if (!vis[v]){
            int subcur = helper(res,mp,v,n,vis);
            if (subcur%2 == 0){
                res++;
            }
            else{
                cur += subcur;
            }
        }
    }
    return cur+1;
}

int solve(int n, vector<vector<int> > &edge){
    unordered_map<int,vector<int>> mp;
    for(auto x : edge){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }
    vector<bool> vis(n+1,false);
    int res = 0;
    helper(res,mp,1,n,vis);
    return res;
}
