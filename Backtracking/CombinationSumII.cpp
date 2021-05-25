//Problem Link:- https://www.interviewbit.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&result,vector<int> temp,vector<int>&nums,int target,int sm,int idx){
    if (sm == target){
        sort(temp.begin(),temp.end());
        result.push_back(temp);
        return;
    }
    if (sm > target){
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if (i == idx || nums[i] != nums[i-1]){
            temp.push_back(nums[i]);
            helper(result,temp,nums,target,sm+nums[i],i+1);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    helper(result,temp,nums,target,0,0);
    return result;
}
