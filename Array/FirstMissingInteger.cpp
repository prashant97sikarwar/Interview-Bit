//Problem Link:- https://www.interviewbit.com/problems/first-missing-integer/

#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        if (nums[i]-1 != i){
            return i+1;
        }
    }
    return n+1;
}
