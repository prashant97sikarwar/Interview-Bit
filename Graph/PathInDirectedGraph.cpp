//problem Link:- https://www.interviewbit.com/problems/path-in-directed-graph/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& visited,unordered_map<int,vector<int>>& graph){
    visited[node] = 1;
    for(int nbr : graph[node]){
        if (visited[nbr] == 0){
            dfs(nbr,visited,graph);
        }
    }
}

int solve(int n, vector<vector<int> > &mat){
    if (n == 1){
        return 1;
    }
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<mat.size();i++){
        graph[mat[i][0]].push_back(mat[i][1]);
    }
    vector<int> visited(n+1,0);
    dfs(1,visited,graph);
    if (visited[n] == 1){
        return 1;
    }
    return 0;
}
