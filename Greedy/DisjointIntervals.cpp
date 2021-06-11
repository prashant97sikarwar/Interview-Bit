//Problem Link:- https://www.interviewbit.com/problems/disjoint-intervals/

#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> first, vector<int> sec){
    return first[1] < sec[1];
}

int solve(vector<vector<int> > &nums){
    sort(nums.begin(),nums.end(),cmp);
    int sz = 1;
    int curr = 0;
    for(int i=1;i<nums.size();i++){
        if (nums[i][0] > nums[curr][1]){
            sz++;
            curr = i;
        }
    }
    return sz;
}
