//Problem Link:- https://www.interviewbit.com/problems/magician-and-chocolates/

#include<bits/stdc++.h>
using namespace std;

int nchoc(int t, vector<int> &nums){
    int n = nums.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
    }
    long long res = 0;
    while (!pq.empty() && t > 0){
        int ch = pq.top();
        res += ch;
        pq.pop();
        pq.push(ch / 2);
        t--;
    }
    return res%1000000007;
}
