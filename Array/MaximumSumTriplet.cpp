//Problem Link:- https://www.interviewbit.com/problems/maximum-sum-triplet/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n = nums.size();
    vector<int> right(n+1,0);
    right[n] = 0;
    for(int i=n-1;i>=0;i--){
        right[i] = max(right[i+1],nums[i]);
    }
    int res = 0;
    set<int> lessVal;
    lessVal.insert(INT_MIN);
    for(int i=0;i<n-1;i++){
        if (right[i+1] > nums[i]){
            auto it = lessVal.lower_bound(nums[i]);
            --it;
            res = max(res,nums[i] + right[i+1] + *it);
            lessVal.insert(nums[i]);
        }
    }
    return res;
}
