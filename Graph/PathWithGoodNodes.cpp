//Problem Link:- https://www.interviewbit.com/old/problems/path-with-good-nodes/

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int visited[100005];
int result;

void helper(int node,vector<int>& nums, int k,int good){
    good += nums[node-1];
    visited[node] = 1;
    bool flag = true;
    for(int child : graph[node]){
        if (visited[child] == 0){
            flag = false;
            helper(child,nums,k,good);
        }
    }
    if (flag && good <= k){
        result++;
    }
}

int solve(vector<int> &nums, vector<vector<int> > &edges, int k){
    int n = nums.size();
    for(int i=0;i<=n;i++){
        graph[i].clear();
        visited[i] = 0;
    }
    result = 0;
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    helper(1,nums,k,0);
    return result;
}
