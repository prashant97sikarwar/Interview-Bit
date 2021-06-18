//Problem link:- https://www.interviewbit.com/old/problems/largest-permutation/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> mp(n+1);
    for(int i=0;i<n;i++){
        mp[nums[i]] = i;
    }
    int i = 0;
    for(int i=0;i<n&&k>0;i++){
        if(nums[i]!=(n-i)) 
        {
            mp[nums[i]]=mp[n-i];
            swap(nums[mp[n-i]],nums[i]);
            k--;
        }
    }
    return nums;
}
