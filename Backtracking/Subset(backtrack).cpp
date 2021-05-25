//Problem Link:- https://www.interviewbit.com/problems/subset/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& result,vector<int>& nums, int i, vector<int>temp){
    if (i >= nums.size()){
        sort(temp.begin(),temp.end());
        result.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    helper(result,nums,i+1,temp);
    temp.pop_back();
    helper(result,nums,i+1,temp);
}

vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    vector<int> temp;
    helper(result,nums,0, temp);
    sort(result.begin(),result.end());
    return result;
}
