//Problem Link:- https://www.interviewbit.com/problems/stepping-numbers/

#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int m,vector<int>& result,int num){
    queue<int> pq;
    pq.push(num);

    while (!pq.empty()){
        int node = pq.front();
        pq.pop();

        if (node <= m && node >= n){
            result.push_back(node);
        }
        if (node == 0 || node > m){
            continue;
        }
        int child1 = node*10 + node%10 + 1;
        int child2 = node*10 + node%10 - 1;
        if (node%10 == 0){
            pq.push(child1);
        }
        else if (node%10 == 9){
            pq.push(child2);
        }
        else{
            pq.push(child1);
            pq.push(child2);
        }

    }
}

vector<int> stepnum(int n, int m) {
    vector<int> result;
    for(int i=0;i<=9;i++){
        bfs(n,m,result,i);
    }
    sort(result.begin(),result.end());
    return result;
}
