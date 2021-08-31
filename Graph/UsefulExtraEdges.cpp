//Problem Link:- https://www.interviewbit.com/old/problems/useful-extra-edges/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100005];

void bfs(int src, int dest, vector<int>& dist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    
    while (!pq.empty()){
        pair<int,int> pr = pq.top();
        pq.pop();
        int node = pr.second;
        int d = pr.first;
        
        for(auto child : graph[node]){
            int childNode = child.first;
            int wt = child.second;
            
            if (dist[childNode] > wt + dist[node]){
                dist[childNode] = wt + dist[node];
                pq.push({dist[childNode],childNode});
            }
        }
    }
}

int solve(int n, vector<vector<int> > &edgeList, int src, int dest, vector<vector<int> > &extraEdges){
    for(int i=0;i<=n;i++){
        graph[i].clear();
    }
    for(auto edge : edgeList){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graph[u].push_back({v,wt});
    }
    vector<int> dist(n+1,INT_MAX);
    bfs(src,dest,dist);
    int low = dist[dest];
    
    for(auto edge : extraEdges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
        fill(dist.begin(),dist.end(),INT_MAX);
        bfs(src,dest,dist);
        low = min(low,dist[dest]);
        graph[u].pop_back();
        graph[v].pop_back();
    }
    return low == INT_MAX ? -1 : low;
}
