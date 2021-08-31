//Problem Link:- https://www.interviewbit.com/old/problems/two-teams/

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];

bool dfs(int node,vector<int>&colors,int cl,vector<bool>& vis){
    vis[node] = true;
    colors[node] = cl;
    for(int child : graph[node]){
        if (vis[child] == false && dfs(child,colors,1-cl,vis) == false){
            return false;
        }
        else if (colors[child] == cl){
            return false;
        }
    }
    return true;
}


int solve(int n, vector<vector<int> > &mat){
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
    for(auto &edge : mat){
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> colors(n+1,2);
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if (colors[i] == 2 && vis[i] == false){
            if (dfs(i,colors,0,vis) == false){
                return 0;
            }
        }
    }
    return 1;
    
}
