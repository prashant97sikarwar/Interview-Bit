//Problem Link:- https://www.interviewbit.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> temp1, vector<int> temp2){
    int i = 0;
    while (i < temp1.size() && i < temp2.size()){
        if (temp1[i] < temp2[i]){
            return true;
        }
        if (temp1[i] == temp2[i]){
            i++;
        }
        else{
            return false;
        }
    }
    return false;
}

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
            helper(result,temp,nums,target,sm+nums[i],i);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    helper(result,temp,nums,target,0,0);
    sort(result.begin(),result.end(),cmp);
    return result;
}
