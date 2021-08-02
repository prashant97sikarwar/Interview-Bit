//Problem Link:- https://www.interviewbit.com/old/problems/knight-on-chess-board/

#include<bits/stdc++.h>
using namespace std;

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

bool valid(int x,int y,int n,int m,vector<vector<int>>&dp){
    if (x < 1 || y < 1 || x > n || y > m || dp[x][y] == 1){
        return false;
    }
    return true;
}

int knight(int n, int m, int xs, int ys, int xd, int yd){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    if (xs == xd && ys == yd){
        return 0;
    }
    queue<pair<int,int>> pq;
    int step = 0;
    pq.push({xs,ys});
    while (!pq.empty()){
        int sz = pq.size();
        while (sz--){
            auto node = pq.front();
            pq.pop();
            int x = node.first;
            int y = node.second;
            if (x == xd && y == yd){
                return step;
            }
            for(int k=0;k<8;k++){
                if (valid(x+dx[k],y+dy[k],n,m,dp)){
                    pq.push({x+dx[k],y+dy[k]});
                    dp[x+dx[k]][y+dy[k]] = 1;
                }
            }
        }
        step++;
    }
    return -1;
}
