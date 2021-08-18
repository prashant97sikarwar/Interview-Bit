//Problem Link:- https://www.interviewbit.com/old/problems/delete-edge/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void dfs(int node,int parent,int& res,int total,vector<int>& subtree,vector<int>graph[]){
    int sm = subtree[node];
    for(int child : graph[node]){
        if (child != parent){
            dfs(child,node,res,total,subtree,graph);
            sm += subtree[child];
        }
    }
    subtree[node] = sm;
    if (node != 0){
        int first = abs(sm)%mod;
        int sec = (abs(total - sm))%mod;
        long long prod = (first*1LL*sec)%mod;
        if (prod > res){
            res = prod%mod;
        }
    }
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> graph[n+1];
    vector<int> subtree(n+2,0);
    int totalSum = 0;
    for(int i=0;i<A.size();i++){
        totalSum += A[i];
        subtree[i] = A[i]; 
    }
    for(auto x : B){
        graph[x[0]-1].push_back(x[1]-1);
        graph[x[1]-1].push_back(x[0]-1);
    }
    
    int res = INT_MIN;
    dfs(0,-1,res,totalSum,subtree,graph);
    return res;
}

