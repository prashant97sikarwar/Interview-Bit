//Problem Link:- https://www.interviewbit.com/problems/merge-k-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int> > &nums){
    int k = nums.size();
    if (k == 0){
        return {};
    }
    int n = nums[0].size();
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(int i=0;i<k;i++){
        vector<int> temp = {nums[i][0],i,0};
        pq.push(temp);
    }
    vector<int> result;
    while (!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int val = x[0], row = x[1], col = x[2];
        result.push_back(val);
        if (col+1 < n){
            vector<int> temp = {nums[row][col+1],row,col+1};
            pq.push(temp);
        }
    }
    return result;
}
