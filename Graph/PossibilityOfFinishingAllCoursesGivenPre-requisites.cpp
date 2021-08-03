//Problem Link:- https://www.interviewbit.com/old/problems/possibility-of-finishing-all-courses-given-prerequisites/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &B, vector<int> &C) {
    vector<int> inDegree(n+1,0);
    vector<int> graph[n+1];
    for(int i=0;i<B.size();i++){
        int u = B[i];
        int v = C[i];
        graph[u].push_back(v);
        inDegree[v]++;
    }
    queue<int> pq;
    vector<int> result;
    for(int i=1;i<=n;i++){
        if (inDegree[i] == 0){
            pq.push(i);   
        }
    }
    while (!pq.empty()){
        int node = pq.front();
        pq.pop();
        result.push_back(node);
        for(int child : graph[node]){
            inDegree[child]--;
            if (inDegree[child] == 0){
                pq.push(child);
            }
        }
    }
    return  (result.size() == n ? 1 : 0);
}
