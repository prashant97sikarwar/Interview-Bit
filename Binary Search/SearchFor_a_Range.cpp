//Problem Link:- https://www.interviewbit.com/problems/search-for-a-range/

#include<bits/stdc++.h>
using namespace std;

int leftpos(const vector<int> &nums,int k){
    int left = 0;
    int right = nums.size()-1;
    int idx = nums.size();
    while(left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == k){
            idx = min(idx,mid);
            right = mid-1;
        }
        else if (nums[mid] > k){
            right = mid-1;
        }
        else if (nums[mid] < k){
            left = mid+1;
        }
    }
    return (idx == nums.size()) ? -1 : idx;
}

int rightpos(const vector<int>& nums, int k){
    int left = 0;
    int right = nums.size()-1;
    int idx = -1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == k){
            idx = max(idx,mid);
            left = mid+1;
        }
        else if (nums[mid] > k){
            right = mid-1;
        }
        else if (nums[mid] < k){
            left = mid+1;
        }
    }
    return idx;
}


vector<int> searchRange(const vector<int> &nums, int k) {
    vector<int> result;
    int l = leftpos(nums,k);
    int r = rightpos(nums,k);
    result.push_back(l);
    result.push_back(r);
    return result;
}
