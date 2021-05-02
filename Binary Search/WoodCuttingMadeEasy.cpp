//Problem Link:- https://www.interviewbit.com/problems/woodcutting-made-easy/

#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums,int k,int h){
    long long sm = 0;
    for(int i=0;i<nums.size();i++){
        if (nums[i] > h){
            sm += nums[i]-h;
        }
    }
    if (sm >= k){
        return true;
    }
    return false;
}

int solve(vector<int> &nums, int k) {
    int left = 0;
    int right = *max_element(nums.begin(),nums.end());
    int res = INT_MIN;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (helper(nums,k,mid)){
            res = max(res,mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return res;
}
