//Problem Link:- https://www.interviewbit.com/problems/cycle-in-undirected-graph/

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,vector<bool>&visited,unordered_map<int,vector<int>> &graph,int parent){
    visited[node] = true;
    for(auto nbr : graph[node]){
        if (visited[nbr] == false){
            bool foundCycle = checkCycle(nbr,visited,graph,node);
            if (foundCycle == true){
                return true;
            }
        }
        else if (nbr != parent){
            return true;
        }
    }
    return false;
}

int solve(int n, vector<vector<int> > &mat){
    if (n == 1){
        return 0;
    }
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<mat.size();i++){
        graph[mat[i][0]].push_back(mat[i][1]);
        graph[mat[i][1]].push_back(mat[i][0]);
    }
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if (visited[i] == false){
            if (checkCycle(i,visited,graph,-1)){
                return 1;
            }
        }
    }
    return 0;
}
