//Problem Link:- https://www.interviewbit.com/problems/profit-maximisation/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    int res = 0;
    while (!pq.empty() && k > 0){
        k--;
        int node = pq.top();
        res += node;
        pq.pop();
        pq.push(node-1);
    }
    return res;
}
