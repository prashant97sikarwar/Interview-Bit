//Problem Link:- https://www.interviewbit.com/problems/counting-triangles/

#include<bits/stdc++.h>
using namespace std;

int nTriang(vector<int> &nums) {
    long long res = 0,n = nums.size();
    long long MOD = 1e9+7;
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>=1;i--){
        int l = 0;
        int r = i-1;
        while (l < r){
            if (nums[l] + nums[r] > nums[i]){
                res += (r-l)%MOD;
                res %= MOD;
                r--;
            }
            else{
                l++;
            }
        }
    }
    return res%MOD;
}
