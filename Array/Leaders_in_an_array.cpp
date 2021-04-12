//Problem Link:- https://www.interviewbit.com/problems/leaders-in-an-array/'

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums) {
    vector<int> result;
    int n = nums.size();
    result.push_back(nums.back());
    int mx = nums.back();
    for(int i=n-2;i>=0;i--){
        if (nums[i] > mx){
            result.push_back(nums[i]);
            mx = nums[i];
        }
    }
    return result;
}