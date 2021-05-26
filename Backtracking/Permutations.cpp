//Problem Link:- https://www.interviewbit.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&result,vector<int> temp,vector<bool>&vis,vector<int>&nums){
    if (temp.size() == nums.size()){
        result.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if (vis[i] == true){
            continue;
        }
        vis[i] = true;
        temp.push_back(nums[i]);
        helper(result,temp,vis,nums);
        vis[i] = false;
        temp.pop_back();
    }
}

vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> temp;
    vector<bool> vis(nums.size(),false);
    helper(result,temp,vis,nums);
    return result;
}
