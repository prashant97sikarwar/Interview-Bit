//Problem Link:- https://www.interviewbit.com/problems/coin-sum-infinite/

#include<bits/stdc++.h>
using namespace std;

int coinchange2(vector<int> &nums, int sm){
    sort(nums.begin(),nums.end());
    vector<long long> dp(sm+1,0);
    dp[0] = 1;
    const int mod = 1000007;
    for(int i=0;i<nums.size();i++){
        for(int j=nums[i];j<=sm;j++){
            dp[j] = dp[j]%mod + dp[j-nums[i]]%mod;
        }
    }
    return dp[sm]%mod;
}
