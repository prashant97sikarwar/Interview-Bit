//Problem link:- https://www.interviewbit.com/old/problems/largest-distance-between-nodes-of-a-tree/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &vis,int curr,vector<vector<int>> &adj,vector<int> &dist)
{
    vis[curr] = true;
    for (int i=0;i<adj[curr].size();i++)
    {
        if(!vis[adj[curr][i]])
        {
            dist[adj[curr][i]] = min(dist[curr] + 1 , dist[adj[curr][i]]);
            dfs(vis,adj[curr][i],adj,dist);
        }
    }
}



int solve(vector<int> &A) {
    int n = A.size(),root;
    vector<int> dist(n,INT_MAX);
    vector<bool> vis(n,false);
    vector<vector<int>> adj(n);
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1){
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
        }
        else root = i;
    }
    dist[root] = 0;
    dfs(vis,root,adj,dist);
    int mindistidx = root;
    for (int i=0;i<n;i++)
    {
        if(dist[i] > dist[mindistidx]) 
        {
            mindistidx = i;
        }
    }
    for (int i=0;i<n;i++) vis[i] = false,dist[i] = INT_MAX;
    dist[mindistidx] = 0;
    dfs(vis,mindistidx,adj,dist);
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        ans = max(ans,dist[i]);
    }
    return ans;
    
}