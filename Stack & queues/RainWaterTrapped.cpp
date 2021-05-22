//Problem Link:- https://www.interviewbit.com/problems/rain-water-trapped/

#include<bits/stdc++.h>
using namespace std;

int trap(const vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = nums[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],nums[i]);
    }
    right[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],nums[i]);
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res += (min(left[i],right[i]) - nums[i]);
    }
    return res;
}
