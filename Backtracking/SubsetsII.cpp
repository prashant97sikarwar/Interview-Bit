//Problem Link:- https://www.interviewbit.com/problems/subsets-ii/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &result,vector<int> temp,vector<int>& nums,set<vector<int>> &s,int idx){
    if (idx >= nums.size()){
        sort(temp.begin(),temp.end());
        if (s.find(temp) == s.end()){
            result.push_back(temp);
            s.insert(temp);
        }
        return;
    }
    temp.push_back(nums[idx]);
    helper(result,temp,nums,s,idx+1);
    temp.pop_back();
    helper(result,temp,nums,s,idx+1);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> temp;
    if (nums.size() == 0){
        return {{}};
    }
    set<vector<int>> s;
    helper(result,temp,nums,s,0);
    sort(result.begin(),result.end());
    return result;
}
