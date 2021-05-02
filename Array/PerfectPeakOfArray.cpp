//Problem Link:- https://www.interviewbit.com/problems/perfect-peak-of-array/

#include<bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2){
        return 0;
    }
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = INT_MIN;
    right[n-1] = INT_MAX;
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],nums[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right[i] = min(nums[i+1],right[i+1]);
    }
    for(int i=1;i<n-1;i++){
        if (nums[i] > left[i] && nums[i] < right[i]){
            return 1;
        }
    }
    return 0;
}
