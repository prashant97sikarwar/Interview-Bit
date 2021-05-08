//Problem Link:- https://www.interviewbit.com/problems/rearrange-array/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums,int n){
    if (n >= nums.size()){
        return;
    }
    int temp = nums[nums[n]];
    solve(nums,n+1);
    nums[n] = temp;
}

void arrange(vector<int> &nums) {
    solve(nums,0);
}
