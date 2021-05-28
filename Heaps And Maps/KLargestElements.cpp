//Problem Link:- https://www.interviewbit.com/problems/k-largest-elements/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, int k){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<int> result;
    for(int i=n-1;i>=n-k;i--){
        result.push_back(nums[i]);
    }
    return result;
}
