//Problem Link:- https://www.interviewbit.com/problems/cycle-in-directed-graph/

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,vector<bool>& visited, vector<bool>& recur,unordered_map<int,vector<int>>&graph){
    visited[node] = true;
    recur[node] = true;
    for(int nbr : graph[node]){
        if (visited[nbr] == false){
            bool foundCycle = checkCycle(nbr,visited,recur,graph);
            if (foundCycle){
                return true;
            }
        }
        else if (recur[nbr] == true){
            return true;
        }
    }
    recur[node] = false;
    return false;
}

int solve(int n, vector<vector<int> > &mat){
    if (n == 1){
        return 0;
    }
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<mat.size();i++){
        graph[mat[i][0]].push_back(mat[i][1]);
    }
    vector<bool> visited(n+1,false);
    vector<bool> recur(n+1,false);
    for(int i=1;i<=n;i++){
        if (visited[i] == false){
            if (checkCycle(i,visited,recur,graph)){
                return 1;
            }
        }
    }
    return 0;
}
