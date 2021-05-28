//Problem Link:- https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums1, vector<int> &nums2, int k){
    int n = nums1.size();
    priority_queue<vector<int>> pq;
    sort(nums1.begin(),nums1.end(),greater<int>());
    sort(nums2.begin(),nums2.end(),greater<int>());
    for(int i=0;i<n;i++){
        int sm = nums1[i] + nums2[0];
        pq.push({sm,i,0});
    }
    vector<int> result;
    while (result.size() < k){
        auto x = pq.top();
        pq.pop();
        int sm = x[0], i = x[1], j = x[2];
        result.push_back(sm);
        pq.push({nums1[i] + nums2[j+1],i,j+1});
    }
    return result;
}

