//Problem Link:- https://www.interviewbit.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

int lis(const vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (nums[i] > nums[j]){
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
    }
    int res = *max_element(dp.begin(),dp.end());
    return res;
}
