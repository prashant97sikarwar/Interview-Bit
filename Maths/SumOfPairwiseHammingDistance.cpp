//Problem Link:- https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

#include<bits/stdc++.h>
using namespace std;

int hammingDistance(const vector<int> &nums) {
    long long MOD = 1000000007;
    long long cnt0 = 0,cnt1 = 0,res = 0;
    for(int i=31;i>=0;i--){
        cnt0 = 0,cnt1 = 0;
        long long mask = 1 << i;
        for(int j=0;j<nums.size();j++){
            if (mask & nums[j]){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }
        res += (cnt0*cnt1)% MOD;
        res %= MOD;
    }
    return 2*res%MOD;
}
