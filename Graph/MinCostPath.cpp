//Problem Link:- https://www.interviewbit.com/old/problems/min-cost-path/

#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solve(int n, int m, vector<string> &mat){
    const int inf = 1e9;
    vector<vector<int>> dist(n,vector<int> (m,inf));
    string s = "URDL";
    deque<pair<int,int>> pq;
    pq.push_front({0,0});
    dist[0][0] = 0;
    while (!pq.empty()){
        auto node = pq.front();
        pq.pop_front();
        int x = node.first;
        int y = node.second;
        if (x == n-1 && y == m-1){
            return dist[x][y];
        }
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            int wt = 0;
            if (s[k] != mat[x][y]){
                wt = 1;
            }
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && wt + dist[x][y] < dist[nx][ny]){
                dist[nx][ny] = wt + dist[x][y];
                if (wt == 0){
                    pq.push_front({nx,ny});
                }
                else{
                    pq.push_back({nx,ny});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
