//Problem Link:- https://www.interviewbit.com/problems/maximum-unsorted-subarray/

#include<bits/stdc++.h>
using namespace std;

vector<int> subUnsort(vector<int> &nums) {
    int i = 0;
    int n = nums.size();
    int j = n-1;
    while (i < n-1 && nums[i] <= nums[i+1]){
        i++;
    }
    while (j > 0 && nums[j] >= nums[j-1]){
        j--;
    }
    if (i == n-1){
        return {-1};
    }
    int mx = nums[i+1],mn = nums[i+1];
    for(int k=i;k<=j;k++){
        mn = min(mn,nums[k]);
        mx = max(mx,nums[k]);
    }
    int l = 0;
    int r = n-1;
    while (l <=i && nums[l] <= mn){
        l++;
    }
    while (r >= j && nums[r] >= mx){
        r--;
    }
    return {l,r};
}
