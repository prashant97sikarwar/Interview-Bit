//Problem Link:- https://www.interviewbit.com/old/problems/commutable-islands/

#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a, vector<int>& b){
    return a[2] < b[2];
}

int find(int u,vector<int>& parent){
    if (u == parent[u]){
        return u;
    }
    return parent[u] = find(parent[u],parent);
}

void merge(int u, int v,vector<int>& parent, vector<int>& rank){
    int x = find(u,parent);
    int y = find(v,parent);
    if (x == y){
        return;
    }
    if (rank[x] > rank[y]){
        parent[y] = x;
        rank[x] += rank[y];
    }
    else{
        parent[x] = y;
        rank[y] += rank[x];
    }
}

int solve(int n, vector<vector<int> > &nums){
    sort(nums.begin(),nums.end(),cmp);
    vector<int> rank(n+1,1);
    vector<int> parent(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    int result = 0;
    for(auto &edge : nums){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (find(u,parent) == find(v,parent)){
            continue;
        }
        else{
            merge(u,v,parent,rank);
            result += w;
        }
    }
    return result;
}

