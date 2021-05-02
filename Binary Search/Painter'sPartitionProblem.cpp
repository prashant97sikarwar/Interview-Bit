//Problem Link:- interviewbit.com/problems/painters-partition-problem/

#include<bits/stdc++.h>
using namespace std;

bool helper(long long min,int k,vector<int> &nums){
    int sm = 0;
    int pan = 1;
    for(int i=0;i<nums.size();i++){
        if (nums[i] > min){
            return false;
        }
        if (nums[i] + sm > min){
            sm = nums[i];
            pan++;
            if (pan > k){
                return false;
            }
        }
        else{
            sm += nums[i];
        }
    }
    if (pan <= k){
        return true;
    }
    return false;
}

int paint(int k, int B, vector<int> &nums) {
    int MOD = 10000003;
    int left = *max_element(nums.begin(),nums.end());
    int right = 0;
    for(int i=0;i<nums.size();i++){
        right += nums[i];
    }
    long long res = INT_MAX;
    while(left <= right){
        long long mid = left + (right-left)/2;
        if (helper(mid,k,nums)){
            res = min(res,mid);
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    res = (1LL*res*B%MOD)%MOD;
    return res;
}
