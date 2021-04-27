//Problem Link:= https://www.interviewbit.com/problems/pick-from-both-sides/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size();
    int sm = 0;
    for(int i=0;i<k;i++){
        sm += nums[i];
    }
    if (k == n){
        return sm;
    }
    int res = sm;
    int right = n-1;
    for(int i=k-1;i>=0;i--){
        sm = sm - nums[i] + nums[right];
        res = max(res,sm);
        right--;
    }
    return res;
}
