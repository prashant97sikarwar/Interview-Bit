//Problem Link:- https://www.interviewbit.com/old/problems/snake-ladder-problem/

#include<bits/stdc++.h>
using namespace std;

int snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    const int target = 100;
    const int n = A.size();
    const int m = B.size();
    vector<int> ladders(101,-1);
    vector<int> snakes(101,-1);
    vector<int> visited(101,0);
    for(int i=0;i<n;i++){
        ladders[A[i][0]] = A[i][1];
    }
    for(int i=0;i<m;i++){
        snakes[B[i][0]] = B[i][1];
    }
    int steps = 0;
    queue<int> pq;
    pq.push(1);
    visited[1] = 1;
    while (!pq.empty()){
        int sz = pq.size();
        while (sz--){
            int node = pq.front();
            if (node == target){
                return steps;
            }
            pq.pop();
            for(int k=1;k<=6;k++){
                int newnode = node+k;
                if (visited[newnode] == 1){
                    continue;
                }
                if (newnode > target){
                    break;
                }
                else if (ladders[newnode] != -1){
                    newnode = ladders[newnode];
                }
                else if (snakes[newnode] != -1){
                    newnode = snakes[newnode];
                }
                pq.push(newnode);
                visited[newnode] = 1;
            }   
        }
        steps++;
    }
    return -1;
}
