//Problem Link:- https://www.interviewbit.com/problems/allocate-books/

#include<bits/stdc++.h>
using namespace std;

bool helper(int page,vector<int>& nums,int k){
    int st = 1;
    int sm = 0;
    for(int i=0;i<nums.size();i++){
        if (nums[i] > page){
            return false;
        }
        if (sm + nums[i] > page){
            sm = nums[i];
            st++;
            if (st > k){
                return false;
            }
        }
        else{
            sm += nums[i];
        }
    }
    if (st <= k){
        return true;
    }
    return false;
}

int books(vector<int> &nums, int k) {
    if (nums.size() < k){
        return -1;
    }
    int left = *max_element(nums.begin(),nums.end());
    int right = 0;
    for(int i=0;i<nums.size();i++){
        right += nums[i];
    }
    int res = INT_MAX;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (helper(mid,nums,k)){
            res = min(res,mid);
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return (res != INT_MAX) ? res : -1;
}
